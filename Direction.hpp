#pragma once

class Direction{
public:
    enum EnumDirection{
        East = 1, West = 2, South = 4, North = 8 
    };

    static EnumDirection GetDirectionAtRandom(EnumDirection choice_direction);

};