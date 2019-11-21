#include "MazeCreatorFactory.hpp"

IMazeCreator* BasicMazeCreatorFactory::Create() const noexcept{
    return new StickDown();
}

