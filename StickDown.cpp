
#include "StickDown.hpp"
#include <stdexcept>
#include <random>
#include "IDirection.hpp"
#include "RandomDirectionSelector.hpp"
#include "GridMazeModel.hpp"
#include <iostream>

StickDown::StickDown(){}

StickDown::StickDown(size_t height, size_t width){
    if(height % 2 == 0 || width % 2 == 0)
        throw std::domain_error("迷路の幅および高さが奇数ではありません");
    _height = height;
    _width = width;
}

IMazeModel* StickDown::Create() const{

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
   
    std::vector<std::string> strvec;
    for(int h = 1; h < _height;h += 2){
        for(int w = 1; w < _width; w += 2){
            if(h != 1){
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
                strvec.push_back(direction->getDirectionName());
            }
            for(int d = 0; d < 4; d++) direction_selector.Valid(d);
        }
    }

    std::vector<std::vector<IStateMazeNode*>> maze_withwall(_height + 2);
    for(int h = 0; h < _height + 2; h++){
        maze_withwall[h] = std::vector<IStateMazeNode*>(_width + 2);
        for(int w = 0;w < _width + 2; w++){
            if(h == 0 || h == _height + 1 || w == 0 || w == _width + 1){
                maze_withwall[h][w] = new StateWall();
            }else{
                maze_withwall[h][w] = maze[h - 1][w - 1];
            }
        }
    }


    
    std::vector<std::vector<Node>> nodes_withwall(_height + 2);
    for(int h = 0; h < _height + 2; h++){
        nodes_withwall[h] = std::vector<Node>(_width + 2);
        for(int w = 0; w < _width + 2; w++){
            nodes_withwall[h][w] = Node(w + h * _width, maze_withwall[h][w]);
        } 
    }
    
    GridMazeModel* model = new GridMazeModel(_height + 2, _width + 2, nodes_withwall);
    return model;
}
