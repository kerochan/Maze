#include "Maze.hpp"
#include <stdexcept>

BasicMazeModel::BasicMazeModel(size_t width, size_t height){
    _width = width;
    _height = height;

    _nodes = new std::vector<Node>(_width * _height);
    _edges = new std::vector<Edge>();
}

BasicMazeModel::BasicMazeModel(size_t width, size_t height, const std::vector<Node>& nodes){
    _width = width;
    _height = height;

    _nodes = new std::vector<Node>(nodes);
    for(Node node : nodes){
        int idx = node.getIndex();
        if (0 <= idx && idx < _width * _height){
            (*_nodes)[idx] = Node(node);
        }
    }
    _edges = new std::vector<Edge>();
}

Node& BasicMazeModel::getNode(int index) const{
    if (0 <= index && index < _width * _height){
        return _nodes->at(index);
    }
    throw std::out_of_range("範囲外のインデックスが指定されました");
}

Edge& BasicMazeModel::getEdge(std::pair<int, int> connection) const{

}

void BasicMazeModel::ChangeNodeData(int index, IStateMazeNode* state){

}

void BasicMazeModel::Connect(int src_index, int dst_index){

}

void BasicMazeModel::Disconnect(int src_index, int dst_index){

}


BasicMazeModel::~BasicMazeModel(){
    delete(_nodes);
    delete(_edges);
}