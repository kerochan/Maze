#pragma once
#include "IMazeModel.hpp"
class GridMazeModel : public IMazeModel{
    size_t _width, _height;

    std::vector<std::vector<Node>>* _node;
public:
    GridMazeModel();
    explicit GridMazeModel(size_t height, size_t width);
    explicit GridMazeModel(size_t height, size_t width, const std::vector<std::vector<Node>>& nodes);  

    Node& getNode(int index) const;
    Node& getNode(int width, int height) const;

    Edge& getEdge(std::pair<int, int> connection) const;
    Edge& getEdge(std::pair<int, int> node1, std::pair<int, int> node2) const;

    const size_t getWidth() const noexcept;
    const size_t getHeight() const noexcept;
   
    void Connect(int src_index, int dst_index);
    void Disconnect(int src_index, int dst_index);
    ~GridMazeModel();
private:
    bool isConnected(std::pair<int, int> connection) const;
    bool isConnected(std::pair<int, int> node1, std::pair<int, int> node2) const;
};