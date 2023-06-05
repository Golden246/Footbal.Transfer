#pragma once
#include <string>
#include <vector>
#include "Player.h"
#include "Trainer.h"
#include "Manager.h"
class Team
{
public:
    Team(const std::string& name, const std::string& country, int moneyLoss);
    ~Team();

    std::string getName() const;
    std::string getCountry() const;
    int getMoneyLoss() const;
    

    void addPlayer(Player* player);
    void removePlayer(Player* player);

    void addTrainer(Trainer* trainer);
    void removeTrainer(Trainer* trainer);

    void addManager(Manager* manager);
    void removeManager(Manager* manager);

    void transferPlayer(Player* player, Team* toTeam, int transferPrice);
    void hireTrainer(Trainer* trainer);
    void hireManager(Manager* manager);

    void paySalaries();

    void setTrainer(Trainer* trainer);

    Manager* getManager() const {
        return manager;
    }
    void setManager(Manager* manager);

    const std::vector<Player*>& getPlayers() const;

    Trainer* getTrainer() const {
        return trainer;
    }

    void payPlayers();
    void payTrainer();
    void payManager();


 
private:
    std::string name;
    std::string country;
    int moneyLoss;
    std::vector<Player*> players;
    std::vector<Trainer*> trainers;
    std::vector<Manager*> managers;
    Trainer* trainer;
    Manager* manager;
};

