#pragma once
#include "Human.h"
class Manager :
    public Human
{
public:
    Manager(const std::string& fullName, int age, int baseSalary, int height);
    virtual ~Manager();

    int getBaseSalary() const;

private:
    int baseSalary;

};

