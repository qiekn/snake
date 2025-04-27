#include "utils.h"

#include "raylib.h"
#include "specs.h"

using namespace snake;

bool utils::InBounds(const Vector2 &position) {
  const auto [x, y] = position;
  return (0 <= x && x < specs::cells_per_row) &&
         (0 <= y && y < specs::cells_per_column);
}

Vector2 utils::GenerateRandomPosition(const int xMax, const int yMax) {
  Vector2 vec;
  vec.x = GetRandomValue(0, xMax);
  vec.y = GetRandomValue(0, yMax);
  return vec;
}
