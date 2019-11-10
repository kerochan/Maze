#pragma once
#include "MazeCreator.hpp"

class WallStretching : public MazeCreator{
    Maze& Create(int maze_height, int maze_width) override;
};