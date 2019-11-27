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
    
    Edge edge = Edge(0, 2);
    std::cout << edge.getConSrcIndex() << " , " << edge.getConDstIndex() << std::endl;
    edge = Edge(std::make_pair(3,4));
    std::cout << edge.getConSrcIndex() << " , " << edge.getConDstIndex() << std::endl;

    std::vector<Node> nodes = std::vector<Node>();
    nodes.push_back(Node(0, new StateWall()));
    nodes.push_back(Node(1, new StateWall()));
    nodes.push_back(Node(2, new StatePassage()));
    nodes.push_back(Node(3, new StatePassage()));

    IMazeModel* maze = new BasicMazeModel(2, 2, nodes);
    std::cout << maze->getNode(0).getState().getNodeString() << std::endl;
    std::cout << maze->getNode(1).getState().getNodeString() << std::endl;
    std::cout << maze->getNode(2).getState().getNodeString() << std::endl;
    std::cout << maze->getNode(3).getState().getNodeString() << std::endl;

    maze->Connect(0, 1);
    maze->Connect(2, 3);
    maze->Connect(2, 1);

    maze->getEdge(std::make_pair(0, 1));
    maze->Disconnect(0, 1);
    
    try{
        //maze->Connect(1, 10);
        //maze->getNode(4);
        //maze->getEdge(std::make_pair(0, 24));
        maze->Disconnect(20,20);
    }catch(std::out_of_range& e){
        std::cerr << e.what() << std::endl;
    }
    //maze->Disconnect(20,20);


    IMazeCreatorFactory* factory = new BasicMazeCreatorFactory(7, 5);
    StickDown* creator = static_cast<StickDown*>(factory->Create());

    

    IMazeCreatorFactory* factory_failed = new BasicMazeCreatorFactory(6, 9);
    try{
        factory_failed->Create();
    }catch(std::domain_error& e){
        std::cout << e.what() << std::endl;
    }

    IDirection* dire = new North();
    std::cout << dire->getDirectionValue() << " : " << "(" << dire->getMovement().first <<  "," << dire->getMovement().second << ")" << std::endl;
    

    North* north = new North();
    South* south = new South();
    West* west = new West();
    East* east = new East();

    RandomDirectionSelector selector;
    selector.Push(north);
    selector.Push(south);
    selector.Push(east);
    selector.Push(west);
    try{
        selector.Invalid(1);
        selector.Invalid(2);
        selector.Invalid(3);
        selector.Invalid(0);

        selector.Valid(0);

        for(int loop = 0; loop < 10; loop++){
            IDirection* direction = selector.getDirection();
            std::cout << direction->getDirectionName() << std::endl;
        }
        
    }catch(std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    IMazeCreatorFactory* f = new BasicMazeCreatorFactory(25, 21);
    StickDown* c = static_cast<StickDown*>(f->Create());
    c->Create();

}