#pragma once
#include <vector>
#include "Node.hpp"
#include "Edge.hpp"

class IMazeModel{
public:
    virtual Node& getNode(int index) const = 0;
    virtual Edge& getEdge(std::pair<int, int> connection) const = 0;
    virtual void Connect(int src_index, int dst_index) = 0;
    virtual void Disconnect(int src_index, int dst_index) = 0;
    virtual ~IMazeModel(){};
};


class BasicMazeModel : public IMazeModel{
    size_t _width, _height;

    //! Nodeオブジェクトを格納するvector Nodeオブジェクトのindexと_nodesのインデックスは一致
    std::vector<Node>* _nodes;
    //! Edgeオブジェクトを格納するvector 
    std::vector<Edge>* _edges;

public:
    BasicMazeModel();
    explicit BasicMazeModel(size_t width, size_t height);
    explicit BasicMazeModel(size_t width, size_t height, const std::vector<Node>& nodes);

    /**
     * @brief indexで指定した値を持つNodeオブジェクトを得る
     * 
     * @param index 得たいNodeオブジェクトのindex
     * @return Node& indexに対応したNodeオブジェクトの参照
     * @details 範囲外のindexを渡すとout_of_range例外を送出
     */
    Node& getNode(int index) const;

    /**
     * @brief connectionで指定したペアを持つEdgeオブジェクトを得る
     * 
     * @param connection 得たいEdgeオブジェクトのpair
     * @return Edge& connectionのペアの値に対応したEdgeオブジェクトの参照
     * @details
     * 
     */
    Edge& getEdge(std::pair<int, int> connection) const;

    /**
     * @brief Nodeオブジェクトのstateを変更する
     * 
     * @param index 変更対象のNodeオブジェクトのindex
     * @param state IStateMazeNodeのオブジェクト
     * @details 範囲外のindexを渡すとout_of_range例外を送出
     */
    void ChangeNodeData(int index, IStateMazeNode* state);
    
    /**
     * @brief 2つのNodeオブジェクトを接続する
     * 
     * @param src_index 接続元のNodeオブジェクトのindex
     * @param dst_index 接続先のNodeオブジェクトのindex
     * @details 範囲外のindexを渡すとout_of_range例外を送出
     */
    void Connect(int src_index, int dst_index);

    void Disconnect(int src_index, int dst_index);

    ~BasicMazeModel();
};