#include "Maze.hpp"
#include <algorithm>
#include <stdexcept>

BasicMazeModel::BasicMazeModel(){}

BasicMazeModel::BasicMazeModel(size_t width, size_t height){
    _width = width;
    _height = height;

    _nodes = new std::vector<Node>(_width * _height);
    _edges = new std::vector<Edge>();
}

BasicMazeModel::BasicMazeModel(size_t width, size_t height, const std::vector<Node>& nodes){
    _width = width;
    _height = height;

    _nodes = new std::vector<Node>(_width * _height);
    for(Node node : nodes){
        int idx = node.getIndex();
        if (0 <= idx && idx < _width * _height){
            (*_nodes)[idx] = Node(node);
        }
    }
    _edges = new std::vector<Edge>();
}

Node& BasicMazeModel::getNode(int index) const{
    return _nodes->at(index);
}

Edge& BasicMazeModel::getEdge(std::pair<int, int> connection) const{
    for(Edge& edge : *_edges){
        int src_idx = edge.getConSrcIndex();
        int dst_idx = edge.getConDstIndex();
        if((src_idx == connection.first && dst_idx == connection.second)
            || (src_idx == connection.second && dst_idx == connection.first)){
            return edge;
        }
    }
    throw std::out_of_range("与えられたペアを持つEdgeオブジェクトが存在しません");
}

void BasicMazeModel::ChangeNodeData(int index, IStateMazeNode* state){
    (*_nodes)[index].setState(state);
}

void BasicMazeModel::Connect(int src_index, int dst_index){
    Edge edge;
    if((0 <= src_index && src_index < _width * _height)
     && (0 <= dst_index && dst_index < _width * _height)){
        edge = Edge(src_index, dst_index);
        _edges->push_back(edge);
        return;
    }
    throw std::out_of_range("与えられたindexが範囲外です");
  
}

void BasicMazeModel::Disconnect(int src_index, int dst_index){
    Edge edge = Edge(src_index, dst_index);
    if(_edges->erase(std::remove_if(_edges->begin(), _edges->end(),
        [&edge](Edge& e){return (e.getConSrcIndex() == edge.getConSrcIndex() && e.getConDstIndex() == edge.getConDstIndex())
         || (e.getConSrcIndex() == edge.getConDstIndex() && e.getConDstIndex() == edge.getConSrcIndex());})) == _edges->end()){
        throw std::out_of_range("与えられたindexが範囲外です");
    }
}


BasicMazeModel::~BasicMazeModel(){
    delete(_nodes);
    delete(_edges);
}