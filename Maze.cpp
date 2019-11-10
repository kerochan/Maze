#include "Maze.hpp"

Maze::Maze(int maze_height, int maze_width){
    _height = maze_height;
    _width = maze_width;
    _maze = new std::vector<int>(maze_height * maze_width);
}

int Maze::operator()(const int h, const int w) const{
    return _maze->at(_width * h + w);
}

void Maze::in(const int h, const int w, const int value){
    _maze->at(_width * h + w) = value;
}

Maze::~Maze(){
    delete(_maze);
}