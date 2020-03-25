#pragma once
#include "IMazeModel.hpp"
#include<cstddef>

/**
 * @brief 迷路を実際に生成するクラス
 * 
 */
class IMazeCreator{
public:
    virtual IMazeModel* Create() const = 0;
    virtual ~IMazeCreator(){};
};
