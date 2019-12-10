
#include "MazeCreator.hpp"
#include <stdexcept>
#include <random>
#include "Maze.hpp"
#include "IDirection.hpp"
#include "RandomDirectionSelector.hpp"
#include <iostream>
#include <cstdlib>

Digging::Digging(){}

Digging::Digging(size_t height, size_t width){
    if(height % 2 == 0 || width % 2 == 0)
        throw std::domain_error("迷路の幅および高さが奇数ではありません");
    _height = height;
    _width = width;
}

IMazeCreator* Digging::Create() const{

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

    auto passstr = StatePassage().getNodeString();
    int linenum = 0;
    //直線かどうか判定
    for(int h = 1; h < _height + 1; h++){
        for(int w = 1;w < _width + 1; w++){
            if((maze_withwall[h - 1][w]->getNodeString() == maze_withwall[h][w]->getNodeString() &&
             maze_withwall[h][w]->getNodeString() == maze_withwall[h + 1][w]->getNodeString() &&
             maze_withwall[h][w]->getNodeString() == passstr) || 
             ((maze_withwall[h][w - 1]->getNodeString() == maze_withwall[h][w]->getNodeString() &&
             maze_withwall[h][w]->getNodeString() == maze_withwall[h][w + 1]->getNodeString() &&
             maze_withwall[h][w]->getNodeString() == passstr))){
                 linenum++;
             }
        }
    }

    auto wallstr = StateWall().getNodeString();
    int crossnum = 0;
    //分岐判定
    for(int h = 1; h < _height + 1; h++){
        for(int w = 1;w < _width + 1; w++){
            if(maze_withwall[h][w]->getNodeString() == passstr){
                 if((maze_withwall[h - 1][w]->getNodeString() == passstr) &&
                    (maze_withwall[h + 1][w]->getNodeString() == passstr) &&
                    (maze_withwall[h][w - 1]->getNodeString() == passstr) &&
                    (maze_withwall[h][w + 1]->getNodeString() == passstr)){
                    crossnum++;
                }
            }
            
        }
    }
    double lineplacerate = static_cast<double>(linenum) / (_width * _height);
    double crossplacerate = static_cast<double>(crossnum) / (_width * _height);
    std::cout << "LinePlaceRate : " << static_cast<double>(linenum) / (_width * _height) << std::endl;
    std::cout << "CrossPlaceRate : " << static_cast<double>(crossnum) / (_width * _height) << std::endl;  
    
    /*
    for(int h = 0; h < _height + 2; h++){
        for(int w = 0;w < _width + 2; w++){
            std::cout << maze_withwall[h][w]->getNodeString();
        }
        std::cout << std::endl;
    }

    */
    FILE* fp;
    fp = fopen("digging.csv", "a");
    fprintf(fp, "%f,%f\n",lineplacerate, crossplacerate);
    fclose(fp);

    std::vector<Node> nodes(_width * _height);
    
    BasicMazeModel maze_model = BasicMazeModel(_height, _width);

    return nullptr;
}

