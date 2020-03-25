#pragma once
#include "IMazeCreator.hpp"

/**
 * @brief 棒倒し法により長方形の迷路を生成するクラス
 * 
 */
class StickDown : public IMazeCreator{
    size_t _width;
    size_t _height;
public:
    StickDown();
    explicit StickDown(size_t height, size_t width);

    IMazeModel* Create() const;
};
