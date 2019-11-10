#pragma once
#include<vector>
#include"Maze.hpp"

class MazeCreator{
public:
    virtual Maze& Create(int maze_height, int maze_width) = 0;
    virtual ~MazeCreator(){};
};