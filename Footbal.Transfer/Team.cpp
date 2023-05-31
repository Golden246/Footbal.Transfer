#include "Team.h"
#include "TransferList.h"

Team::Team(const std::string& name, const std::string& country, int moneyLoss)
    : name(name), country(country), moneyLoss(moneyLoss) {}

Team::~Team() {
    // Освобождаем память от игроков
    for (Player* player : players) {
        delete player;
    }
    // Освобождаем память от тренеров
    for (Trainer* trainer : trainers) {
        delete trainer;
    }
    // Освобождаем память от менеджеров
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
    // Ищем игрока в списке и удаляем его
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);
    }
}

void Team::addTrainer(Trainer* trainer) {
    trainers.push_back(trainer);
}

void Team::removeTrainer(Trainer* trainer) {
    // Ищем тренера в списке и удаляем его
    auto it = std::find(trainers.begin(), trainers.end(), trainer);
    if (it != trainers.end()) {
        trainers.erase(it);
    }
}

void Team::addManager(Manager* manager) {
    managers.push_back(manager);
}

void Team::removeManager(Manager* manager) {
    // Ищем менеджера в списке и удаляем его
    auto it = std::find(managers.begin(), managers.end(), manager);
    if (it != managers.end()) {
        managers.erase(it);
    }
}

void Team::transferPlayer(Player* player, Team* toTeam, int transferPrice) {
    // Проверяем, что игрок находится в текущей команде
    auto it = std::find(players.begin(), players.end(), player);
    if (it != players.end()) {
        players.erase(it);  // Удаляем игрока из текущей команды
        toTeam->addPlayer(player);  // Добавляем игрока в новую команду

        // Создаем объект класса "Трансферный лист"
        TransferList transferList(player, this, toTeam, transferPrice);
        // Решаем стоимость трансфера в соответствии с трансферной ценой
        transferList.resolveTransfer();

        // Вычитаем стоимость трансфера из денег текущей команды
        moneyLoss += transferList.getTransferPrice();
        // Добавляем стоимость трансфера к деньгам новой команды
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
    // Выплата зарплаты игрокам
    for (Player* player : players) {
        int totalSalary = player->getBaseSalary() + player->getTransferPrice();
        moneyLoss -= totalSalary;
    }
    // Выплата зарплаты тренерам
    for (Trainer* trainer : trainers) {
        moneyLoss -= trainer->getSalary();
    }
    // Выплата зарплаты менеджерам
    for (Manager* manager : managers) {
        moneyLoss -= manager->getSalary();
    }
}
