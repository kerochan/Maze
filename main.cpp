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
   
}