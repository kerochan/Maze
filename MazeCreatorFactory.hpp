#pragma once
#include"Maze.hpp"

class IMazeCreatorFactory{
public:
    virtual IMazeCreatorFactory* Create() const noexcept = 0;
    virtual ~IMazeCreatorFactory(){};
};

class BasicMazeCreatorFactory : public IMazeCreatorFactory{    
public:
    IMazeCreatorFactory* create() const noexcept;
};
