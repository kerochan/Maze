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

//pdcurses‚Ì‰Šú‰»?????
void CursesInit(){
    initscr();

    nodelay(stdscr, TRUE);
    noecho();
}

//pdcurses‚ÌI??ˆ??
void CursesTerminate(){
    endwin();
}


//ƒƒCƒ“‚Ìˆ??
void CursesMain(){
   
}