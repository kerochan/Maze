#include "curses.h"


void CursesInit();
void CursesMain();
void CursesTerminate();

int main(){

    CursesInit();

    CursesMain();

    CursesTerminate();

    return 0;
}

//pdcurses�̏�����?????
void CursesInit(){
    initscr();

    nodelay(stdscr, TRUE);
    noecho();
}

//pdcurses�̏I??��??
void CursesTerminate(){
    endwin();
}


//���C���̏�??
void CursesMain(){
   
}