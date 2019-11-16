#pragma once

class IMazeCreator{
public:
    virtual IMazeCreator* Create() const = 0;
    ~IMazeCreator(){};
};

class BasicMazeCreator : public IMazeCreator{
public:
    IMazeCreator* Create() const ;
};


