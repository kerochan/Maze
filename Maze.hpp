#pragma once
#include "Node.hpp"
#include "Edge.hpp"

class IMazeModel{
public:
    virtual Node& getNode(int index) const = 0;
    virtual Edge& getEdge(std::pair<int, int> connection) const = 0;
    virtual ~IMazeModel();

};