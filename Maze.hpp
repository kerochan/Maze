#pragma once
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

class IMazeModel{
public:
    virtual Node& getNode(int index) const = 0;
    virtual Edge& getEdge(std::pair<int, int> connection) const = 0;
    virtual void Connect(int src_index, int dst_index) = 0;
    virtual void Disconnect(int src_index, int dst_index) = 0;
    virtual ~IMazeModel(){};
};

//’·•ûŒ`‚Ì–À˜H
class BasicMazeModel : public IMazeModel{
    size_t _width, _height;

    std::vector<Node>* _nodes;
    std::vector<Edge>* _edges;

public:
    explicit BasicMazeModel(size_t width, size_t height);
    explicit BasicMazeModel(size_t width, size_t height, const std::vector<Node>& nodes);

    Node& getNode(int index) const;
    Edge& getEdge(std::pair<int, int> connection) const;

    void ChangeNodeData(int index, IStateMazeNode* state);
    void Connect(int src_index, int dst_index);
    void Disconnect(int src_index, int dst_index);

    ~BasicMazeModel();
};
