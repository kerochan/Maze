#include "IDirection.hpp"

int North::getDirectionValue() const noexcept{
    return 0;
}

std::string North::getDirectionName() const noexcept{
    return "North";
}

std::pair<int ,int> North::getMovement() const noexcept{
    return std::pair<int, int>(-1, 0);
}


int South::getDirectionValue() const noexcept{
    return 1;
}

std::string South::getDirectionName() const noexcept{
    return "South";
}

std::pair<int ,int> South::getMovement() const noexcept{
    return std::pair<int, int>(1, 0);
}

int West::getDirectionValue() const noexcept{
    return 2;
}

std::string West::getDirectionName() const noexcept{
    return "West";
}

std::pair<int ,int> West::getMovement() const noexcept{
    return std::pair<int, int>(0, -1);
}

int East::getDirectionValue() const noexcept{
    return 3;
}

std::string East::getDirectionName() const noexcept{
    return "East";
}

std::pair<int ,int> East::getMovement() const noexcept{
    return std::pair<int, int>(0, 1);
}