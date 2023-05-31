#pragma once
#include "Human.h"
class Player :
    public Human
{
public:
    Player(const std::string& fullName, int age, int height,
           const std::string& position, int transferPrice, int baseSalary);
    virtual ~Player();

    std::string getPosition() const;
    int getTransferPrice() const;
    int getBaseSalary() const;

private:
    std::string position;
    int transferPrice;
    int baseSalary;
};

