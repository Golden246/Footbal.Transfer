#include "Trainer.h"

Trainer::Trainer(const std::string& fullName, int age, int height,
    int experience, int salary)
    : Human(fullName, age, height), experience(experience), baseSalary(salary) {}

Trainer::~Trainer() {}

int Trainer::getExperience() const {
    return experience;
}

int Trainer::getBaseSalary() const {
    return baseSalary;
}
