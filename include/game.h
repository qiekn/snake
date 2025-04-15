#pragma once

#include "apple.h"
#include "drawable.h"
#include "raylib.h"
#include "snake.h"

namespace snake {

class Game : public Drawable {
 public:
  Game();
  ~Game();
  void Run();

 private:
  void Draw() const override;
  void update();
  bool shouldMoveSnake() const;
  void handleSnakeCollision(const Collision collision);
  void handleSnakeKeyPress();
  void createSnake();
  void spawnNewApple();
  void reset();
  int currentGameScore() const;
  void displayScore() const;

 private:
  Apple _apple;
  Snake _snake;
  Direction _nextSnakeDirection = Direction::None;
  Sound _eatSound;
  Sound _selfCollisionSound;
  Sound _wallCollisionSound;
  bool _isRunning = false;
};

}  // namespace snake
