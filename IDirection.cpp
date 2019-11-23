#include "IDirection.hpp"

int North::getDirectionValue() const noexcept{
    return 0;
}

std::pair<int ,int> North::getMovement() const noexcept{
    return std::pair<int, int>(0, -1);
}

int South::getDirectionValue() const noexcept{
    return 1;
}

std::pair<int ,int> South::getMovement() const noexcept{
    return std::pair<int, int>(0, 1);
}

int West::getDirectionValue() const noexcept{
    return 2;
}

std::pair<int ,int> West::getMovement() const noexcept{
    return std::pair<int, int>(-1, 0);
}

int East::getDirectionValue() const noexcept{
    return 3;
}

std::pair<int ,int> East::getMovement() const noexcept{
    return std::pair<int, int>(1, 0);
}