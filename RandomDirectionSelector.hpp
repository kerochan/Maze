#pragma once
#include<vector>
#include<random>
#include "IDirection.hpp"

/**
 * @brief 乱数で方角を決定するシステムを提供するクラス
 * 
 */
class RandomDirectionSelector{
    size_t _table_length = 0;
    size_t _valid_length = 0;
    std::vector<IDirection*> _random_table;
    std::vector<int> _valid_table;
    
public:

    /**
     * @brief 選択肢となる方角を追加する
     * 
     * @param dire 追加するIDirectionクラスのポインタ
     */
    void Push(IDirection* dire) noexcept;
    void Valid(int index);
    void Invalid(int index);
    IDirection* getDirection() const;
};