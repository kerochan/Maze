#pragma once
#include"utility"

class Edge{
    std::pair<int, int> _connection;
public:
    explicit Edge(int connection_src, int connection_dst);
    explicit Edge(std::pair<int, int> connection);

    int getConSrcIndex() const noexcept;
    int getConDstIndex() const noexcept;
    
};