#pragma once
#include"IStateMazeNode.hpp"

class Node{
    int _index;
    IStateMazeNode* _state;
public:
    void setState(IStateMazeNode* state);
};