#pragma once
#include"IStateMazeNode.hpp"

class Node{
    int _index;
    IStateMazeNode* _state;
public:
    Node();
    explicit Node(int index);
    explicit Node(int index, IStateMazeNode* state);

    void setState(IStateMazeNode* state) noexcept;
    int getIndex() const noexcept;
    const IStateMazeNode& getState() const noexcept;
};
