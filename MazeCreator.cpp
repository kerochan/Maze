
#include "MazeCreator.hpp"
#include <stdexcept>
#include <random>
#include "Maze.hpp"
#include "IDirection.hpp"

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

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    //東西南北のどれかを表す
    std::uniform_int_distribution dist(0, 3);

    for(int h = 1; h < _height;h += 2){
        for(int w = 1; w < _width; w += 2){
            //最初の列に関しては上方向に棒を倒せる
            if(h == 1){
                
            }else{
                
            }
        }
    }

    std::vector<Node> nodes(_width * _height);
    
    BasicMazeModel maze_model = BasicMazeModel(_height, _width);
}