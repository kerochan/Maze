#include<iostream>
#include "curses.h"
#include "IStateMazeNode.hpp"
#include "Node.hpp"

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


//メインの処??
void CursesMain(){
    IStateMazeNode* state;
    state = new StateWall();
    std::cout << state->getNodeString() << std::endl;
    delete(state);
    state = new StatePassage();
    std::cout << state->getNodeString() << std::endl;
    
    Node node = Node(0, state);
    std::cout << node.getIndex() << " : " << node.getState().getNodeString() << std::endl;
    node.setState(new StateWall());
    std::cout << node.getIndex() << " : " << node.getState().getNodeString() << std::endl;
    
    

}