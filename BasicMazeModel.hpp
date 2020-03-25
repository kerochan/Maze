#pragma once
#include "IMazeModel.hpp"

class BasicMazeModel : public IMazeModel{
    size_t _width, _height;

    //! Node�I�u�W�F�N�g���i�[����vector Node�I�u�W�F�N�g��index��_nodes�̃C���f�b�N�X�͈�v
    std::vector<Node>* _nodes;
    //! Edge�I�u�W�F�N�g���i�[����vector 
    std::vector<Edge>* _edges;

public:
    BasicMazeModel();
    explicit BasicMazeModel(size_t width, size_t height);
    explicit BasicMazeModel(size_t width, size_t height, const std::vector<Node>& nodes);

    /**
     * @brief index�Ŏw�肵���l������Node�I�u�W�F�N�g�𓾂�
     * 
     * @param index ������Node�I�u�W�F�N�g��index
     * @return Node& index�ɑΉ�����Node�I�u�W�F�N�g�̎Q��
     * @details �͈͊O��index��n����out_of_range��O�𑗏o
     */
    Node& getNode(int index) const;

    /**
     * @brief connection�Ŏw�肵���y�A������Edge�I�u�W�F�N�g�𓾂�
     * 
     * @param connection ������Edge�I�u�W�F�N�g��pair
     * @return Edge& connection�̃y�A�̒l�ɑΉ�����Edge�I�u�W�F�N�g�̎Q��
     * @details
     * 
     */
    Edge& getEdge(std::pair<int, int> connection) const;

    /**
     * @brief Node�I�u�W�F�N�g��state��ύX����
     * 
     * @param index �ύX�Ώۂ�Node�I�u�W�F�N�g��index
     * @param state IStateMazeNode�̃I�u�W�F�N�g
     * @details �͈͊O��index��n����out_of_range��O�𑗏o
     */
    void ChangeNodeData(int index, IStateMazeNode* state);

    /**
     * @brief 2��Node�I�u�W�F�N�g��ڑ�����
     * 
     * @param src_index �ڑ�����Node�I�u�W�F�N�g��index
     * @param dst_index �ڑ����Node�I�u�W�F�N�g��index
     * @details �͈͊O��index��n����out_of_range��O�𑗏o
     */
    void Connect(int src_index, int dst_index);

    void Disconnect(int src_index, int dst_index);

    ~BasicMazeModel();
};