#pragma once

#include <chrono>
#include <filesystem>

#include "raylib.h"

namespace snake::specs {

/* TODO: change constant name -> kCellSize <2025-04-20 00:50, @qiekn> */
constexpr int cell_size = 64;
constexpr int cells_per_row = 12;
constexpr int cells_per_column = 12;
constexpr int window_width = cell_size * cells_per_row;
constexpr int window_height = cell_size * cells_per_column;
constexpr auto window_title = "game";
constexpr int fps = 60;
constexpr Color backgrond_color{0xdf, 0xff, 0x94, 0xff};
constexpr Color snake_head_color{0x64, 0x8f, 0x00, 0xff};
constexpr Color snake_color{0x40, 0x5c, 0x00, 0xff};
constexpr Color snake_tail_color{0x2b, 0x3d, 0x00, 0xff};
constexpr Color apple_color{0xff, 0x48, 0x24, 0xff};
constexpr int initial_sanke_body_length = 3;
constexpr std::chrono::milliseconds sanke_move_rate{90};
constexpr int score_font_size = 42;
constexpr Color score_color = DARKGRAY;
inline const std::filesystem::path resources_dir = SNAKE_RESOURCES;
inline const std::filesystem::path sounds_dir = resources_dir / "sounds";
inline const std::filesystem::path sanke_eat_sound =
    sounds_dir / "snake_eat.wav";
inline const std::filesystem::path snake_self_collision =
    sounds_dir / "snake_self_collision.wav";
inline const std::filesystem::path snakeWallCollision =
    sounds_dir / "snake_wall_collision.wav";

}  // namespace snake::specs
