#include "game.h"

#include <chrono>

#include "apple.h"
#include "raylib.h"
#include "snake.h"
#include "specs.h"
#include "utils.h"

using namespace snake;

Game::Game() {
  InitWindow(specs::window_width, specs::window_height, specs::window_title);
  SetTargetFPS(specs::fps);
  InitAudioDevice();
  eat_sound_ = LoadSound(specs::sanke_eat_sound.string().c_str());
  self_collision_sound_ =
      LoadSound(specs::snake_self_collision.string().c_str());
  wall_collision_sound_ = LoadSound(specs::snakeWallCollision.string().c_str());
}

Game::~Game() {
  UnloadSound(eat_sound_);
  UnloadSound(self_collision_sound_);
  UnloadSound(wall_collision_sound_);
  CloseAudioDevice();
  CloseWindow();
}

void Game::Run() {
  is_running_ = true;
  CreateSnake();
  SpawnNewApple();
  while (!WindowShouldClose() && is_running_) {
    Update();
    Draw();
  }
  if (!WindowShouldClose()) Run();
}

void Game::Draw() const {
  BeginDrawing();
  ClearBackground(specs::backgrond_color);
  apple_.Draw();
  snake_.Draw();
  DisplayScore();
  EndDrawing();
}

void Game::Update() { HandleSnakeKeyPress(); }

bool Game::ShouldMoveSnake() const {
  using namespace std::chrono;
  static time_point prevSnakeMovementTime = high_resolution_clock::now();
  const time_point now = high_resolution_clock::now();
  const milliseconds timePassed =
      duration_cast<milliseconds>(now - prevSnakeMovementTime);
  if (timePassed >= specs::sanke_move_rate) {
    prevSnakeMovementTime = now;
    return true;
  }
  return false;
}

void Game::HandleSnakeCollision(const Collision collision) {
  switch (collision) {
    case Collision::Apple:
      SpawnNewApple();
      PlaySound(eat_sound_);
      break;
    case Collision::Self:
      PlaySound(self_collision_sound_);
      Reset();
      break;
    case Collision::Wall:
      PlaySound(wall_collision_sound_);
      Reset();
      break;
    default:
      break;
  }
}

void Game::CreateSnake() {
  snake_ = Snake(utils::GenerateRandomPosition(
      specs::cells_per_row - specs::initial_sanke_body_length - 1,
      specs::cells_per_column - 1));
}

void Game::SpawnNewApple() {
  Vector2 newApplePosition{};
  do {
    newApplePosition = utils::GenerateRandomPosition();
  } while (snake_.CollidesWith(newApplePosition));
  apple_ = Apple(newApplePosition);
}

void Game::Reset() {
  is_running_ = false;
  next_sanke_direction_ = Direction::None;
}

int Game::CurrentGameScore() const {
  return snake_.SnakeLength() - specs::initial_sanke_body_length;
}

void Game::DisplayScore() const {
  DrawText(TextFormat("score : %d", CurrentGameScore()), specs::cell_size,
           specs::cell_size, specs::score_font_size, specs::score_color);
}

void Game::HandleSnakeKeyPress() {
  switch (GetKeyPressed()) {
    case KEY_UP:
    case KEY_W:
    case KEY_K:
      next_sanke_direction_ = Direction::Up;
      break;
    case KEY_RIGHT:
    case KEY_D:
    case KEY_L:
      next_sanke_direction_ = Direction::Right;
      break;
    case KEY_DOWN:
    case KEY_S:
    case KEY_J:
      next_sanke_direction_ = Direction::Down;
      break;
    case KEY_LEFT:
    case KEY_A:
    case KEY_H:
      next_sanke_direction_ = Direction::Left;
      break;
  }

  if (ShouldMoveSnake()) {
    const Collision snakeMovementCollision =
        snake_.Move(next_sanke_direction_, apple_.GetPosition());
    HandleSnakeCollision(snakeMovementCollision);
  }
}
