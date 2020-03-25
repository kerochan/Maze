CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

FILE(GLOB BASESRCS
    "BasicMazeModel.cpp"
    "GridMazeModel.cpp"
)

FILE(GLOB HEADERS
    "BasicMazeModel.hpp"
    "GridMazeModel.hpp"
    "IMazeModel.hpp"
)

ADD_LIBRARY(mazemodel SHARED ${BASESRCS})