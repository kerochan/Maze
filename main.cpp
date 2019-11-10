#include "curses.h"
#include"DisjointSet.cpp"
#include "MazeEnum.hpp"
//#include "WallStretching.hpp"
#include<random>
#include<chrono>

void CursesInit();
void CursesMain();
void CursesTerminate();

int main(){

    CursesInit();

    CursesMain();

    CursesTerminate();

    return 0;
}

//pdcursesの初期化?????
void CursesInit(){
    initscr();

    nodelay(stdscr, TRUE);
    noecho();
}

//pdcursesの終??処??
void CursesTerminate(){
    endwin();
}

constexpr int INF = 9999999;

//メインの処??
void CursesMain(){
    std::vector<std::vector<Node<int>*>> maze = std::vector<std::vector<Node<int>*>>();
    //0 未占有 : それ以外 占有済み
    std::vector<std::vector<int>> occupied = std::vector<std::vector<int>>();

    int width = 30, height = 20;

    for(int h = 0; h < height; h++){
        maze.push_back(std::vector<Node<int>*>(width));
        occupied.push_back(std::vector<int>(width));
        for(int w = 0; w < width; w++){
            maze[h][w] = DisjointSet<int>::MakeSet(w + h * width);
            occupied[h][w] = 0;
        }
    }
    auto edge = std::vector<std::tuple<int, int, int>>();
    std::mt19937 engine(static_cast<unsigned int>(std::chrono::system_clock::to_time_t(std::chrono::system_clock::now())));
    std::uniform_int_distribution<int> weight_dist(0, width * height - (width + height));

    for(int w = 0; w < width; w++){
        for(int h = 0; h < height - 1; h++){
            
            int weight = 0;
            int center = w + width * h;

            weight = weight_dist(engine); 

            edge.push_back(std::make_tuple(center, center + width, weight));
        }
    }

    for(int w = 0; w < width - 1; w++){
        for(int h = 0; h < height; h++){
            
            int weight = 0;
            int center = w + width * h;

            weight = weight_dist(engine); 
            
            edge.push_back(std::make_tuple(center, center + 1, weight));
        }
    }

    std::sort(edge.begin(), edge.end(), 
        [](std::tuple<int, int, int> t1, std::tuple<int, int, int> t2){return std::get<2>(t1) < std::get<2>(t2);});

    for(auto v : edge){
        std::cout << std::get<0>(v) <<" " << std::get<1>(v) << " " << std::get<2>(v) << std::endl;
    }

    
    for(auto e : edge){
        int begin = std::get<0>(e);
        int end = std::get<1>(e);
        int weight = std::get<2>(e);

        int begin_h = begin / width, begin_w = begin - (begin / width) * width;
        int end_h = end / width, end_w  = end - (end / width) * width;

        if(!(weight == INF)){
            DisjointSet<int>::Union(*(maze[begin_h][begin_w]),
                 *(maze[end_h][end_w]));
            occupied[begin_h][begin_w] = 1;
            
        }

        
    }

    for(auto facts : maze){
        for(auto fact : facts){
            auto tempfact = fact;
            std::cout << tempfact->val << " " << (tempfact == tempfact->parent) << std::endl;
            
        }
    }

    
    for(auto facts : maze){
        for(auto fact : facts){
            auto tempfact = fact;
            bool loop_cond = false;
            do{
                std::cout << tempfact->val << " ";
                loop_cond = (tempfact != tempfact->parent);
                tempfact = tempfact->parent;
            }while(loop_cond);
            std::cout << std::endl;
        }
    
    }

    int maze_height = 2 * height + 1, maze_width = 2 * width + 1;

    std::vector<std::vector<EnumMazeState>> print_maze = std::vector<std::vector<EnumMazeState>>(maze_height);
    for(int h = 0; h < maze_height; h++){
        print_maze[h] = std::vector<EnumMazeState>(maze_width);
        for(int w = 0; w < maze_width; w++){
            print_maze[h][w] = EnumMazeState::Wall;
        }
    }
    for(int h = 0; h < height; h++){
        for(int w = 0; w < width; w++){
           
            auto tempfact = maze[h][w];
            bool loop_cond = false;
            int grid_h = 0, grid_w = 0;
            do{
                
                loop_cond = (tempfact != tempfact->parent);
                grid_h = tempfact->val / width;
                grid_w = tempfact->val - (tempfact->val / width) * width;
                if(loop_cond){
                    int grid_h_p = tempfact->parent->val / width, grid_w_p = tempfact->parent->val - (tempfact->parent->val / width) * width;
                    print_maze[grid_h + grid_h_p + 1][grid_w + grid_w_p + 1] = EnumMazeState::Passage;
                    
                }
                print_maze[2 * grid_h + 1][2 * grid_w + 1] = EnumMazeState::Passage;
                
                tempfact = tempfact->parent;
            }while(loop_cond);
        }
    }

     for(int h = 0; h < maze_height; h++){
        for(int w = 0; w < maze_width; w++){
            switch (print_maze[h][w])
            {
            case EnumMazeState::Wall:
                std::cout << "@@";
                break;
            case EnumMazeState::Passage:
                std::cout << "  ";
                break;
            default:
                break;
            }
            
        }
        std::cout << std::endl;
    }
   
}