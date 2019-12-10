#include"Maze.hpp"
#include <stdexcept>

GridMazeModel::GridMazeModel(size_t height, size_t width){
    _height = height;
    _width = width;
    size_t node_size = _height * _width;

    _node = new std::vector<std::vector<Node>>(_height);
    _edge = new std::vector<std::vector<Edge>>(_height*_width);

    for(int h = 0; h < _height; h++){
        (*_node)[h] = std::vector<Node>(_width);
    }

    for(int n1 = 0; n1 < node_size; n1++){
        (*_edge)[n1] = std::vector<Edge>(node_size);
        for(int n2 = 0; n2 < node_size; n2++) (*_edge)[n1][n2] = Edge(n1, n2);
    }
}

GridMazeModel::GridMazeModel(size_t height, size_t width, const std::vector<std::vector<Node>>& nodes){
    _height = height;
    _width = width;
    size_t node_size = _height * _width;

    _node = new std::vector<std::vector<Node>>(_height);
    _edge = new std::vector<std::vector<Edge>>(_height*_width);

    for(int h = 0; h < _height; h++){
        (*_node)[h] = std::vector<Node>(_width);
        for(int w = 0; w < _width; w++) (*_node)[h][w] = Node(w + h * _width);
    }

    for(int n1 = 0; n1 < node_size; n1++){
        (*_edge)[n1] = std::vector<Edge>(node_size);
        for(int n2 = 0; n2 < node_size; n2++) (*_edge)[n1][n2] = Edge(n1, n2);
    }
}

Node& GridMazeModel::getNode(int index) const{
    if(0 <= index && index < _height * _width){
        return (*_node)[index / _width][index - (index / _width) * _width];
    }
    throw std::out_of_range("範囲外のインデックスが渡されました");
}

Node& GridMazeModel::getNode(int height, int width) const{
    return getNode(width + _width * height);
}

Edge& GridMazeModel::getEdge(std::pair<int, int> connection) const{
    if(isConnected(connection)) return (*_edge)[connection.first][connection.second];
    throw std::out_of_range("範囲外のインデックスが渡されました");
}

Edge& GridMazeModel::getEdge(std::pair<int, int> node1, std::pair<int, int> node2) const{
    return getEdge(std::make_pair<int, int>(node1.second + _width * node1.first, node2.second + _width * node2.first));
}

void GridMazeModel::Connect(int src_index, int dst_index){
    getNode(src_index).setState(new StateWall());
    getNode(src_index).setState(new StateWall());
}

void GridMazeModel::Disconnect(int src_index, int dst_index){
    getNode(src_index).setState(new StatePassage());
    getNode(src_index).setState(new StatePassage());
}

GridMazeModel::~GridMazeModel(){
    delete(_node);
    delete(_edge);
}

bool GridMazeModel::isConnected(std::pair<int, int> connection) const{
    if((0 <= connection.first && connection.first < _height * _width) &&
     (0 <= connection.second && connection.second < _height * _width)){
        if(getNode(connection.first).getState() == getNode(connection.second).getState()){
            if(getNode(connection.first).getState() == StatePassage()){
                return true;
            }
        }
        return false;
    }
    throw std::out_of_range("範囲外のインデックスが渡されました");
}

bool GridMazeModel::isConnected(std::pair<int, int> node1, std::pair<int, int> node2) const{
    return isConnected(std::make_pair(node1.second + _width * node1.first, node2.second + _width * node2.first));
}

