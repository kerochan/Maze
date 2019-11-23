#pragma once
#include"Maze.hpp"
#include"MazeCreator.hpp"

class IMazeCreatorFactory{
public:
    virtual IMazeCreator* Create() const = 0;
    virtual ~IMazeCreatorFactory(){};
};

class BasicMazeCreatorFactory : public IMazeCreatorFactory{
    size_t _height;
    size_t _width;
public:    
    explicit BasicMazeCreatorFactory(size_t height, size_t width);
    IMazeCreator* Create() const ;
};
