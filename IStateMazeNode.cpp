#include "IStateMazeNode.hpp"

std::string StateWall::getNodeString() const noexcept{
    return "@@";
}

std::string StatePassage::getNodeString() const noexcept{
    return "  ";
}