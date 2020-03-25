#pragma once
#include <utility>
#include <string>

class IDirection{
public:
    virtual int getDirectionValue() const noexcept = 0;
    virtual std::string getDirectionName() const noexcept = 0;
    virtual std::pair<int, int> getMovement() const noexcept = 0;
    virtual ~IDirection(){};
};

class North :public IDirection{
public:
    int getDirectionValue() const noexcept;
    std::string getDirectionName() const noexcept;
    std::pair<int, int> getMovement() const noexcept;
};

class South :public IDirection{
public:
    int getDirectionValue() const noexcept;
    std::string getDirectionName() const noexcept;
    std::pair<int, int> getMovement() const noexcept;
};

class West :public IDirection{
public:
    int getDirectionValue() const noexcept;
    std::string getDirectionName() const noexcept;
    std::pair<int, int> getMovement() const noexcept;
};

class East :public IDirection{
public:
    int getDirectionValue() const noexcept;
    std::string getDirectionName() const noexcept;
    std::pair<int, int> getMovement() const noexcept;
};