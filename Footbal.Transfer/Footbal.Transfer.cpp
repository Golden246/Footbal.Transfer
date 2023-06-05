#include <iostream>
#include "Team.h"

int main() {
    std::string command;
    std::vector<Team*> teams;


    while (true) {
        std::cout << "1. Create a team\n"
            << "2. Create a player\n"
            << "3. Create a trainer\n"
            << "4. Create manager\n"
            << "5. Move player to another team\n"
            << "6. Pay salary\n"
            << "7. View team information\n"
            << "8. List of commands\n"
            << "9. Exit the program\n"
            << "Select an action: ";

        std::cin >> command;

        if (command == "1") {
            std::string name, country;
            int moneyLoss;

            std::cout << "Enter team name: ";
            std::cin >> name;

            std::cout << "Enter team country: ";
            std::cin >> country;

            std::cout << "Enter the loss of money on the team's account: ";
            std::cin >> moneyLoss;

            Team* team = new Team(name, country, moneyLoss);
            teams.push_back(team);

            std::cout << "Team created\n";
        }
        else if (command == "2") {
            std::string fullName, position;
            int age, height, transferPrice, baseSalary;

            std::cout << "Enter the player's name: ";
            std::cin.ignore();
            std::getline(std::cin, fullName);

            std::cout << "Enter the player's age: ";
            std::cin >> age;

            std::cout << "Enter player height: ";
            std::cin >> height;

            std::cout << "Enter player position: ";
            std::cin.ignore();
            std::getline(std::cin, position);

            std::cout << "Enter the player's transfer price: ";
            std::cin >> transferPrice;

            std::cout << "Enter player's base salary: ";
            std::cin >> baseSalary;

            Player* player = new Player(fullName, age, height, position, transferPrice, baseSalary);

            std::cout << "Select a team to add a player:\n";
            for (int i = 0; i < teams.size(); i++) {
                std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
            }

            int teamIndex;
            std::cin >> teamIndex;

            if (teamIndex >= 1 && teamIndex <= teams.size()) {
                Team* team = teams[teamIndex - 1];
                team->addPlayer(player);
                std::cout << "Player added to team " << team->getName() << std::endl;
            }
            else {
                std::cout << "Incorrect team selection\n";
            }
        }
        else if (command == "3") {
            std::string fullName;
            int age, experience, baseSalary, height;
            std::cout << "Enter trainer's name: ";
            std::cin.ignore();
            std::getline(std::cin, fullName);

            std::cout << "Enter trainer's age: ";
            std::cin >> age;

            std::cout << "Enter trainer height: ";
            std::cin >> height;

            std::cout << "Enter the number of years of trainer experience: ";
            std::cin >> experience;

            std::cout << "Enter coach base salary: ";
            std::cin >> baseSalary;

            Trainer* trainer = new Trainer(fullName, age, height, experience, baseSalary);

            std::cout << "Select a team to add a trainer:\n";
            for (int i = 0; i < teams.size(); i++) {
                std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
            }

            int teamIndex;
            std::cin >> teamIndex;

            if (teamIndex >= 1 && teamIndex <= teams.size()) {
                Team* team = teams[teamIndex - 1];
                team->setTrainer(trainer);
                std::cout << "Trainer added to the team" << team->getName() << std::endl;
            }
            else {
                std::cout << "Incorrect team selection\n";
            }
        }
        else if (command == "4") {
            std::string fullName;
            int age, baseSalary, height;

            std::cout << "Enter manager's name: ";
            std::cin.ignore();
            std::getline(std::cin, fullName);

            std::cout << "Enter manager's age: ";
            std::cin >> age;

            std::cout << "Enter manager height: ";
            std::cin >> height;

            std::cout << "Enter the manager's base salary: ";
            std::cin >> baseSalary;

            Manager* manager = new Manager(fullName, age, height, baseSalary);

            std::cout << "Select a command to add a manager:\n";
            for (int i = 0; i < teams.size(); i++) {
                std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
            }

            int teamIndex;
            std::cin >> teamIndex;

            if (teamIndex >= 1 && teamIndex <= teams.size()) {
                Team* team = teams[teamIndex - 1];
                team->setManager(manager);
                std::cout << "Manager added to the team " << team->getName() << std::endl;
            }
            else {
                std::cout << "Incorrect team selection\n";
            }
        }
        else if (command == "5") {
            std::cout << "Select the team from which you want to transfer the player:\n";
            for (int i = 0; i < teams.size(); i++) {
                std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
            }

            int teamIndex;
            std::cin >> teamIndex;

            if (teamIndex >= 1 && teamIndex <= teams.size()) {
                Team* teamFrom = teams[teamIndex - 1];

                std::cout << "Select the team to which you want to transfer the player:\n";
                for (int i = 0; i < teams.size(); i++) {
                    if (i != (teamIndex - 1)) {
                        std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
                    }
                }

                int targetTeamIndex;
                std::cin >> targetTeamIndex;

                if (targetTeamIndex >= 1 && targetTeamIndex <= teams.size()) {
                    Team* teamTo = teams[targetTeamIndex - 1];

                    std::cout << "Select a player to transfer:\n";
                    for (int i = 0; i < teamFrom->getPlayers().size(); i++) {
                        std::cout << i + 1 << ". " << teamFrom->getPlayers()[i]->getName() << std::endl;
                    }

                    int playerIndex;
                    std::cin >> playerIndex;

                    if (playerIndex >= 1 && playerIndex <= teamFrom->getPlayers().size()) {
                        Player* player = teamFrom->getPlayers()[playerIndex - 1];
                        teamFrom->removePlayer(player);
                        teamTo->addPlayer(player);
                        std::cout << "Player " << player->getName() << " transferred to the team " << teamTo->getName() << std::endl;
                    }
                    else {
                        std::cout << "Incorrect player selection\n";
                    }
                }
                else {
                    std::cout << "Incorrect team selection\n";
                }
            }
            else {
                std::cout << "Incorrect team selection\n";
            }
        }
        else if (command == "6") {
            std::cout << "Choose a payroll team:\n";
            for (int i = 0; i < teams.size(); i++) {
                std::cout << i + 1 << ". " << teams[i]->getName() << std::endl;
            }

            int teamIndex;
            std::cin >> teamIndex;

            if (teamIndex >= 1 && teamIndex <= teams.size()) {
                Team* team = teams[teamIndex - 1];
                
                team->payPlayers();

                team->payTrainer();

                team->payManager();

                std::cout << "Salary paid for the team " << team->getName() << std::endl;
            }
            else {
                std::cout << "Incorrect team selection\n";
            }
        }
        else if (command == "7") {
            std::cout << "Enter team name: ";
            std::string teamName;
            std::cin >> teamName;

            bool found = false;
            for (Team* team : teams) {
                if (team->getName() == teamName) {
                    found = true;
                    std::cout << "Team name: " << team->getName() << std::endl;
                    std::cout << "Players:\n";
                    team->getPlayers();
                    std::cout << "Trainer: " << team->getTrainer() << std::endl;
                    std::cout << "Manager: " << team->getManager() << std::endl;
                    break;
                }
            }

            if (!found) {
                std::cout << "The team with the name " << teamName << " not found.\n";
            }
            }
        else if (command == "8") {
                std::cout << "Command List:\n";
                for (const auto& team : teams) {
                    std::cout << team->getName() << std::endl;
                }
                std::cout << "---------------------------\n";
                }
        else if (command == "9") {
            std::cout << "The program has ended.\n";
            break;
        }
        else {
            std::cout << "Incorrect command\n";
        }

        std::cout << "---------------------------\n";
    }

    for (Team* team : teams) {
        delete team;
    }

    return 0;
}