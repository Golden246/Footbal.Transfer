#include "Team.h"
#include "TransferList.h"

Team::Team(const std::string& name, const std::string& country, int moneyLoss)
    : name(name), country(country), moneyLoss(moneyLoss) {}

Team::~Team() {
    // ����������� ������ �� �������
    for (Player* player : players) {
        delete player;
    }
    // ����������� ������ �� ��������
    for (Trainer* trainer : trainers) {
        delete trainer;
    }
    // ����������� ������ �� ����������
    for (Manager* manager : managers) {
        delete manager;
    }
}

std::string Team::getName() const {
    return name;
}

std::string Team::getCountry() const {
    return country;
}

int Team::getMoneyLoss() const {
    return moneyLoss;
}

void Team::addPlayer(Player* player) {
    players.push_back(player);
}

void Team::removePlayer(Player* player) {
    // ���� ������ � ������ � ������� ���
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
    }
}

void Team::addTrainer(Trainer* trainer) {
    trainers.push_back(trainer);
}

void Team::removeTrainer(Trainer* trainer) {
    // ���� ������� � ������ � ������� ���
    auto it = std::find(trainers.begin(), trainers.end(), trainer);
    if (it != trainers.end()) {
        trainers.erase(it);
    }
}

void Team::addManager(Manager* manager) {
    managers.push_back(manager);
}

void Team::removeManager(Manager* manager) {
    // ���� ��������� � ������ � ������� ���
    auto it = std::find(managers.begin(), managers.end(), manager);
    if (it != managers.end()) {
        managers.erase(it);
    }
}

void Team::transferPlayer(Player* player, Team* toTeam, int transferPrice) {
    // ���������, ��� ����� ��������� � ������� �������
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);  // ������� ������ �� ������� �������
        toTeam->addPlayer(player);  // ��������� ������ � ����� �������

        // ������� ������ ������ "����������� ����"
        TransferList transferList(player, this, toTeam, transferPrice);
        // ������ ��������� ��������� � ������������ � ����������� �����
        transferList.resolveTransfer();

        // �������� ��������� ��������� �� ����� ������� �������
        moneyLoss += transferList.getTransferPrice();
        // ��������� ��������� ��������� � ������� ����� �������
        toTeam->moneyLoss -= transferList.getTransferPrice();
    }
}

void Team::hireTrainer(Trainer* trainer) {
    trainers.push_back(trainer);
}

void Team::hireManager(Manager* manager) {
    managers.push_back(manager);
}

void Team::paySalaries() {
    // ������� �������� �������
    for (Player* player : players) {
        int totalSalary = player->getBaseSalary() + player->getTransferPrice();
        moneyLoss -= totalSalary;
    }
    // ������� �������� ��������
    for (Trainer* trainer : trainers) {
        moneyLoss -= trainer->getSalary();
    }
    // ������� �������� ����������
    for (Manager* manager : managers) {
        moneyLoss -= manager->getSalary();
    }
}
