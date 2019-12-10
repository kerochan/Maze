#include<iostream>
//#include "curses.h"
#include "IStateMazeNode.hpp"
#include "Node.hpp"
#include"Edge.hpp"
#include"Maze.hpp"
#include"MazeCreatorFactory.hpp"
#include "IDirection.hpp"
#include "RandomDirectionSelector.hpp"

void CursesInit();
void CursesMain();
void CursesTerminate();


int main(){
 CursesInit();

    CursesMain();

    CursesTerminate();

    return 0;
}


void CursesInit(){
    //initscr();

    //nodelay(stdscr, TRUE);
    //noecho();
}


void CursesTerminate(){
    //endwin();
}



void CursesMain(){
    IMazeCreatorFactory* f = new BasicMazeCreatorFactory(99, 99);
    StickDown* c = static_cast<StickDown*>(f->Create());
    for(int i = 0; i < 100; i++){
        c->Create();
    }
    
}