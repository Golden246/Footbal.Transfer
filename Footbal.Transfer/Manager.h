#pragma once
#include "Human.h"
class Manager :
    public Human
{
public:
    Manager(const std::string& fullName, int age, int height, int salary);
    virtual ~Manager();

    int getSalary() const;

private:
    int salary;

};

