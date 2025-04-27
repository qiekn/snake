#include "apple.h"

#include "raylib.h"
#include "specs.h"

using namespace snake;

Apple::Apple(const Vector2 &position) : _position(position) {}

Vector2 Apple::GetPosition() const { return _position; }

void Apple::Draw() const {
  const int xPos = specs::cell_size * (_position.x + 0.5F);
  const int yPos = specs::cell_size * (_position.y + 0.5F);
  DrawCircle(xPos, yPos, specs::cell_size / 2.0F, specs::apple_color);
}
