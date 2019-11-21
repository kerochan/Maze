#pragma once
#include<cstddef>

/**
 * @brief 迷路を実際に生成するクラス
 * 
 */
class IMazeCreator{
public:
    virtual IMazeCreator* Create() const = 0;
    virtual ~IMazeCreator(){};
};

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

    IMazeCreator* Create() const;
};
