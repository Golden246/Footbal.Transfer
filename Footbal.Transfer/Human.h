#pragma once

#include <string>

class Human {
public:
    Human(const std::string& fullName, int age, int height);
    virtual ~Human();

    std::string getFullName() const;
    int getAge() const;
    int getHeight() const;

private:
    std::string fullName;
    int age;
    int height;


};


