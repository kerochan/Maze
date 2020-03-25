#pragma once
#include<string>

class IStateMazeNode{
public:
    virtual std::string getNodeString() const noexcept = 0;
    virtual ~IStateMazeNode(){};

    bool operator==(const IStateMazeNode& rhs) const;
    bool operator!=(const IStateMazeNode& rhs) const;
};

class StateWall : public IStateMazeNode{
public:
    std::string getNodeString() const noexcept;

};

class StatePassage : public IStateMazeNode{
public:
    std::string getNodeString() const noexcept;

};