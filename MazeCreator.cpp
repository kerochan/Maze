
#include "MazeCreator.hpp"
#include <stdexcept>
#include <random>
#include "Maze.hpp"
#include "IDirection.hpp"
#include "RandomDirectionSelector.hpp"

#include <iostream>

StickDown::StickDown(){}

StickDown::StickDown(size_t height, size_t width){
    if(height % 2 == 0 || width % 2 == 0)
        throw std::domain_error("迷路の幅および高さが奇数ではありません");
    _height = height;
    _width = width;
}

IMazeCreator* StickDown::Create() const{

    //二次元配列を用いて迷路をモデル化
    std::vector<std::vector<IStateMazeNode*>> maze(_height);
    for(int h = 0; h < _height;h++){
        maze[h] = std::vector<IStateMazeNode*>(_width);
        for(int w = 0; w < _width; w++){
            //迷路が(奇数,奇数)の座標は壁にする
            if(w % 2 == 1 && h % 2 == 1) maze[h][w] = new StateWall();
            else maze[h][w] = new StatePassage();
        }
    }

    RandomDirectionSelector direction_selector;
    direction_selector.Push(new North());
    direction_selector.Push(new East());
    direction_selector.Push(new South());
    direction_selector.Push(new West());
   


    for(int h = 1; h < _height;h += 2){
        for(int w = 1; w < _width; w += 2){
            if(w != 1){
                direction_selector.Invalid(0);
            }
            if(maze[h - 1][w]->getNodeString() == maze[h][w]->getNodeString()){
                direction_selector.Invalid(0);
            }
            if(maze[h][w + 1]->getNodeString() == maze[h][w]->getNodeString()){
                direction_selector.Invalid(1);
            }
            if(maze[h + 1][w]->getNodeString() == maze[h][w]->getNodeString()){
                direction_selector.Invalid(2);
            }
            if(maze[h][w - 1]->getNodeString() == maze[h][w]->getNodeString()){
                direction_selector.Invalid(3);
            }
            
            if(!direction_selector.isAllInvalid()){
                IDirection* direction = direction_selector.getDirection();
                maze[h + direction->getMovement().first][w + direction->getMovement().second] = new StateWall();
                std::cout << h << "," << w << ":" << direction->getDirectionName() << std::endl;;
            }
            for(int d = 0; d < 4; d++) direction_selector.Valid(d);
        }
    }

    for(int h = 0; h < _height; h++){
        for(int w = 0;w < _width; w++){
            std::cout << maze[h][w]->getNodeString();
        }
        std::cout << std::endl;
    }

    std::vector<Node> nodes(_width * _height);
    
    BasicMazeModel maze_model = BasicMazeModel(_height, _width);

    return nullptr;
}