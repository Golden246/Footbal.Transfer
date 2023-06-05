#include "Manager.h"

Manager::Manager(const std::string& fullName, int age,int baseSalary, int height)
    : Human (fullName, age, height), baseSalary(baseSalary) {}

Manager::~Manager() {}


int Manager::getBaseSalary() const {
    return baseSalary;
}
