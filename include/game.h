#pragma once

#include "apple.h"
#include "drawable.h"
#include "raylib.h"
#include "snake.h"

namespace snake {

class Game : public Drawable {
 public:
  Game();
  virtual ~Game();
  void Run();

 private:
  void Draw() const override;
  void Update();
  bool ShouldMoveSnake() const;
  void HandleSnakeCollision(const Collision collision);
  void HandleSnakeKeyPress();
  void CreateSnake();
  void SpawnNewApple();
  void Reset();
  int CurrentGameScore() const;
  void DisplayScore() const;

 private:
  Apple apple_;
  Snake snake_;
  Direction next_sanke_direction_ = Direction::None;
  Sound eat_sound_;
  Sound self_collision_sound_;
  Sound wall_collision_sound_;
  bool is_running_ = false;
};

}  // namespace snake
