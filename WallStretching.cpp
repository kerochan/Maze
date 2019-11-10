#include "WallStretching.hpp"
#include <random>
#include <algorithm>
#include "MazeEnum.hpp"

Maze& WallStretching::Create(int maze_height, int maze_width){

    //迷路の幅と高さは5以上かつ奇数
    if(maze_height >= 5 && maze_width >= 5
     && maze_height % 2 == 1 && maze_width % 2 == 1){
        
        Maze* maze = new Maze(maze_height, maze_width);
        //迷路の周囲を壁で囲む
        for(int h = 0; h < maze->getHeight(); h++){
            for(int w = 0; w < maze->getWidth(); w++){
                if(h == 0 || h == maze->getHeight() - 1 || w == 0 || w == maze->getWidth() - 1)
                    maze->in(w, h, static_cast<int>(EnumMazeState::Wall));
            }
        }

        //壁伸ばし開始地点をスタックに積む
        int stretch_point_num = (maze->getHeight() / 2 + 1) * (maze->getWidth() / 2 + 1);
        std::vector<int>* stretch_point_list = new std::vector<int>(stretch_point_num);
        for(int h = 0; h < maze->getHeight(); h += 2){
            for(int w = 0; w < maze->getWidth(); w += 2){
                stretch_point_list->push_back(maze->getWidth() * h + w);
            }
        }

        //壁伸ばし開始地点、および伸ばす方向を決定するための乱数生成器の作成
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen);
        std::uniform_int_distribution<int> stretch_point_dist(0, stretch_point_num - 1);
        std::uniform_int_distribution<int> direction_dist(static_cast<int>(EnumDirection::North),
             static_cast<int>(EnumDirection::West));

        //迷路の壁のクラスタリング 格納値はクラスタ番号
        Maze* classified_maze = new Maze(*maze);
        for(int h = 0; h < classified_maze->getHeight(); h++){
            for(int w = 0; w < classified_maze->getWidth(); w++){
                if(h == 0 || h == classified_maze->getHeight() - 1 || w == 0 || w == maze->getWidth() - 1)
                    classified_maze->in(w, h, 0);
                else
                    classified_maze->in(w, h, -1);
            }
        }

        //壁伸ばし地点が壁で埋まるまでループ
        while(!stretch_point_list->empty()){
            //壁伸ばし地点をランダムに選出
            int stretch_point_index = stretch_point_dist(engine);
            stretch_point_list->erase(stretch_point_list->begin() + stretch_point_index);

            //選出された点から延ばされた壁のインデックスを保存する配列
            std::vector<int>* stretched_point_list = new std::vector<int>();
            

            while(!stretched_point_list->empty()){
                stretched_point_list->push_back(stretch_point_index);
                maze->in(stretch_point_index,stretch_point_index / maze->getWidth(),static_cast<int>(EnumMazeState::Wall));
                
                auto stretch_direction = static_cast<EnumDirection>(direction_dist(engine));

              
            }
        }

        return *maze;


        
    }
    


}