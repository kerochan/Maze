#include "Edge.hpp"



Edge::Edge(int connection_src, int connection_dst){
    _connection = std::make_pair(connection_src, connection_dst);
}

Edge::Edge(std::pair<int, int> connection){
    _connection = connection;
}

int Edge::getConSrcIndex() const noexcept{
    return _connection.first;
}

int Edge::getConDstIndex() const noexcept{
    return _connection.second;
}
