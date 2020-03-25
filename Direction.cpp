#include "Direction.hpp"
#include <cmath>
#include <array>
#include <random>

Direction::EnumDirection Direction::GetDirectionAtRandom(Direction::EnumDirection choice_direction){
    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());
    int int_choice_direction = static_cast<int>(choice_direction);
    int choice_dire_num = 0;
    std::vector<Direction::EnumDirection> valid_dire;
    for(int i = 3; i >= 0; i++){
        if(((int_choice_direction >>i) & 0b1) == 1) valid_dire.push_back(static_cast<Direction::EnumDirection>(static_cast<int>(pow(2, i + 1))));
    }
    std::uniform_int_distribution<> dist(0, choice_direction);
    int random_number = dist(engine);
    Direction::EnumDirection choosen_dire = valid_dire.at(random_number);
    return choosen_dire;
}