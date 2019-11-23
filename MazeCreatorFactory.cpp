#include "MazeCreatorFactory.hpp"

BasicMazeCreatorFactory::BasicMazeCreatorFactory(size_t height, size_t width){
    _height = height;
    _width = width;
}

IMazeCreator* BasicMazeCreatorFactory::Create() const{
    return new StickDown(_width, _height);
}

