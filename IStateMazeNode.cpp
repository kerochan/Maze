#include "IStateMazeNode.hpp"

bool IStateMazeNode::operator==(const IStateMazeNode& rhs) const{ return this->getNodeString() == rhs.getNodeString();}
bool IStateMazeNode::operator!=(const IStateMazeNode& rhs) const{ return !(*this == rhs);}

std::string StateWall::getNodeString() const noexcept{
    return "@@";
}

std::string StatePassage::getNodeString() const noexcept{
    return "  ";
}
