#include "Human.h"

Human::Human(const std::string& fullName, int age, int height)
    : fullName(fullName), age(age), height(height) {}

Human::~Human() {}

std::string Human::getFullName() const {
    return fullName;
}

int Human::getAge() const {
    return age;
}

int Human::getHeight() const {
    return height;
}
