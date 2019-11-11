#include "IStateMazeNode.hpp"


char StateWall::getChar() const noexcept{
    return '@@';
}

char StatePassage::getChar() const noexcept{
    return '  ';
}