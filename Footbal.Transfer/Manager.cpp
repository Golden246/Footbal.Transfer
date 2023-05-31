#include "Manager.h"

Manager::Manager(const std::string& fullName, int age, int height, int salary)
    : Human(fullName, age, height), salary(salary) {}

Manager::~Manager() {}

int Manager::getSalary() const {
    return salary;
}
