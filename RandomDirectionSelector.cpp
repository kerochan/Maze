#include "RandomDirectionSelector.hpp"
#include <stdexcept>
#include <ctime>

void RandomDirectionSelector::Push(IDirection* dire) noexcept{
    _random_table.push_back(dire);
    _valid_table.push_back(1);
    _table_length++;
    _valid_length++;
}

void RandomDirectionSelector::Valid(int index){
    if(0 <= index && index < _table_length){
        if(_valid_table[index] == 0){
            _valid_table[index] = 1;
            _valid_length++;
        }
    }
}

void RandomDirectionSelector::Invalid(int index){
     if(0 <= index && index < _table_length){
        if(_valid_table[index] == 1){
            _valid_table[index] = 0;
            _valid_length--;
        }
    }
}

IDirection* RandomDirectionSelector::getDirection() const{
    if(_valid_length == 0) throw std::out_of_range("有効な要素が存在しません");
    std::uniform_int_distribution<> dist(0, _valid_length - 1);
    std::mt19937 engine(static_cast<int>(clock()));
    int random_value = dist(engine);

    for(int idx = 0; idx < _table_length; idx++){
        if(_valid_table[idx] == 1) random_value--;
        if(random_value < 0){
            return _random_table[idx];
        }
    }
}