#pragma once
#include<vector>

class Maze{
    int _height, _width;
    std::vector<int>* _maze;
public:
    Maze(int maze_height, int maze_width);
    ~Maze();

    int operator()(const int h, const int w) const;
    void in(const int h, const int w, const int value);

    inline int getHeight() const{
        return _height;
    };

    inline int getWidth() const{
        return _width;
    };

};