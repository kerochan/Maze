#pragma once

class IStateMazeNode{
public:
    virtual char getChar() const noexcept = 0;
    virtual ~IStateMazeNode(){};
};

class StateWall : public IStateMazeNode{
public:
    char getChar() const noexcept;

};

class StatePassage : public IStateMazeNode{
public:
    char getChar() const noexcept;
};