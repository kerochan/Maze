#pragma once
#include"Maze.hpp"
#include"MazeCreator.hpp"

class IMazeCreatorFactory{
public:
    virtual IMazeCreator* Create() const noexcept = 0;
    virtual ~IMazeCreatorFactory(){};
};

class BasicMazeCreatorFactory : public IMazeCreatorFactory{    
public:
    IMazeCreator* Create() const noexcept;
};
