#include "Player.h"

Player::Player(const std::string& fullName, int age, int height,
               const std::string& position, int transferPrice, int baseSalary)
    : Human(fullName, age, height), position(position),
    transferPrice(transferPrice), baseSalary(baseSalary) {}

Player::~Player() {}

std::string Player::getPosition() const {
    return position;
}

int Player::getTransferPrice() const {
    return transferPrice;
}

int Player::getBaseSalary() const {
    return baseSalary;
}

std::string Player::getName() const
{
    return std::string();
}