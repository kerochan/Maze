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
    for(int i = 13; i < 14; i += 2){
        IMazeCreatorFactory* f = new BasicMazeCreatorFactory(i*2 + 3, i);
        StickDown* c = static_cast<StickDown*>(f->Create());
        c->Create();
    }
    
}