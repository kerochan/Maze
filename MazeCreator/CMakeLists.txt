CMAKE_MINIMUM_REQUIRED(VERSION 3.10.2)

FILE(GLOB BASESRCS
    "Digging.cpp"
    "StickDown.cpp"
)

FILE(GLOB HEADERS
    "IMazeCreator.hpp"
    "Digging.hpp"
    "StickDown.hpp"
)

ADD_LIBRARY(mazecreator SHARED ${BASESRCS})