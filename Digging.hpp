#pragma once
#include"IMazeCreator.hpp"

/**
 * @brief 穴掘り法により長方形の迷路を生成するクラス
 * 
 */
class Digging : public IMazeCreator{
    size_t _width;
    size_t _height;
public:
    Digging();
    explicit Digging(size_t height, size_t width);

    IMazeModel* Create() const;
};
