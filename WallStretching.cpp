#include "WallStretching.hpp"
#include <random>
#include <algorithm>
#include "MazeEnum.hpp"

Maze& WallStretching::Create(int maze_height, int maze_width){

    //���H�̕��ƍ�����5�ȏォ�
    if(maze_height >= 5 && maze_width >= 5
     && maze_height % 2 == 1 && maze_width % 2 == 1){
        
        Maze* maze = new Maze(maze_height, maze_width);
        //���H�̎��͂�ǂň͂�
        for(int h = 0; h < maze->getHeight(); h++){
            for(int w = 0; w < maze->getWidth(); w++){
                if(h == 0 || h == maze->getHeight() - 1 || w == 0 || w == maze->getWidth() - 1)
                    maze->in(w, h, static_cast<int>(EnumMazeState::Wall));
            }
        }

        //�ǐL�΂��J�n�n�_���X�^�b�N�ɐς�
        int stretch_point_num = (maze->getHeight() / 2 + 1) * (maze->getWidth() / 2 + 1);
        std::vector<int>* stretch_point_list = new std::vector<int>(stretch_point_num);
        for(int h = 0; h < maze->getHeight(); h += 2){
            for(int w = 0; w < maze->getWidth(); w += 2){
                stretch_point_list->push_back(maze->getWidth() * h + w);
            }
        }

        //�ǐL�΂��J�n�n�_�A����ѐL�΂����������肷�邽�߂̗���������̍쐬
        std::random_device seed_gen;
        std::mt19937 engine(seed_gen);
        std::uniform_int_distribution<int> stretch_point_dist(0, stretch_point_num - 1);
        std::uniform_int_distribution<int> direction_dist(static_cast<int>(EnumDirection::North),
             static_cast<int>(EnumDirection::West));

        //���H�̕ǂ̃N���X�^�����O �i�[�l�̓N���X�^�ԍ�
        Maze* classified_maze = new Maze(*maze);
        for(int h = 0; h < classified_maze->getHeight(); h++){
            for(int w = 0; w < classified_maze->getWidth(); w++){
                if(h == 0 || h == classified_maze->getHeight() - 1 || w == 0 || w == maze->getWidth() - 1)
                    classified_maze->in(w, h, 0);
                else
                    classified_maze->in(w, h, -1);
            }
        }

        //�ǐL�΂��n�_���ǂŖ��܂�܂Ń��[�v
        while(!stretch_point_list->empty()){
            //�ǐL�΂��n�_�������_���ɑI�o
            int stretch_point_index = stretch_point_dist(engine);
            stretch_point_list->erase(stretch_point_list->begin() + stretch_point_index);

            //�I�o���ꂽ�_���牄�΂��ꂽ�ǂ̃C���f�b�N�X��ۑ�����z��
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