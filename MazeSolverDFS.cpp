#include "MazeSolverDFS.hpp"
#include <stdexcept>

MazeSolverDFS::MazeSolverDFS(){}
std::vector<Node>& MazeSolverDFS::Solve(const size_t sindex, const size_t gindex, const GridMazeModel& model){
    Node& snode = model.getNode(sindex);
    Node& gnode = model.getNode(gindex);
    
    StatePassage statepass = StatePassage();
    StateWall statewall = StateWall();
    if(snode.getState() == statewall ||  gnode.getState() == statewall) throw std::domain_error("開始地点または終了地点が壁です");
    
}