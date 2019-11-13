#include"Node.hpp"

Node::Node(){}

Node::Node(int index){
    _index = index;
}

Node::Node(int index, IStateMazeNode* state){
    _index = index;
    _state = state;
}

void Node::setState(IStateMazeNode* state) noexcept{
    _state = state;
}

int Node::getIndex() const noexcept{
    return _index;
}

const IStateMazeNode& Node::getState() const noexcept{
    return *_state;
}