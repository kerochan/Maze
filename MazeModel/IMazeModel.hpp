#pragma once
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

/**
 * @brief 迷路のモデルを表現するインターフェース
 * 
 */
class IMazeModel{
public:
    /**
     * @brief indexに応じたNodeオブジェクトの参照を得る関数
     * 
     * @param index 取得したいNodeオブジェクトのインデックス
     * @return Node& インデックスに応じたNodeオブジェクトの参照
     */
    virtual Node& getNode(int index) const = 0;

    /**
     * @brief connectionのペアで示された二つのインデックス間のEdgeオブジェクトの参照を得る関数
     * 
     * @param connection 取得したいEdgeオブジェクトのインデックスのペア
     * @return Edge& インデックスのペアに応じたEdgeオブジェクトの参照
     */
    virtual Edge& getEdge(std::pair<int, int> connection) const = 0;

    /**
     * @brief 与えられた二つのインデックス間のNodeオブジェクトを接続する
     * 
     * @param src_index 接続元のインデックス
     * @param dst_index 接続先のインデックス
     */
    virtual void Connect(int src_index, int dst_index) = 0;

    /**
     * @brief 与えられた二つのインデックス間のNodeオブジェクトの接続を解除する
     * 
     * @param src_index 接続元のインデックス
     * @param dst_index 接続先のインデックス
     */
    virtual void Disconnect(int src_index, int dst_index) = 0;

    /**
     * @brief デストラクタ
     * 
     */
    virtual ~IMazeModel(){};
};