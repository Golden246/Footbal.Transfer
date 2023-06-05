#pragma once
#include "Human.h"
class Trainer :
    public Human
{
public:
    Trainer(const std::string& fullName, int age,int height, 
            int experience, int salary);
    virtual ~Trainer();

    int getExperience() const;
    int getBaseSalary() const;

private:
    int experience;
    int baseSalary;
};

