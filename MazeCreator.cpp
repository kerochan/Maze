#include "MazeCreator.hpp"
#include "Maze.hpp"

StickDown::StickDown(){}

StickDown::StickDown(size_t height, size_t width){
    _height = height;
    _width = width;
}

IMazeCreator* StickDown::Create() const{
    return nullptr;
}