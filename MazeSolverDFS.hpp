#pragma once
#include "GridMazeModel.hpp"
class MazeSolverDFS{

std::vector<Node> _solution;

public:
    MazeSolverDFS();
    std::vector<Node>& Solve(const size_t sindex, const size_t gindex, const GridMazeModel& model);
};