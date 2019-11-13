#include "Maze.hpp"

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
    _edges = new std::vector<Edge>();
}

Node& BasicMazeModel::getNode(int index) const{

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