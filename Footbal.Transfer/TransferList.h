#pragma once
#include "Player.h"
#include "Team.h"
class TransferList
{
public:
    TransferList(Player* player, Team* sourceTeam, Team* destinationTeam, int transferPrice);
    ~TransferList();

    void resolveTransfer();

    int getTransferPrice() const;

private:
    Player* player;
    Team* sourceTeam;
    Team* destinationTeam;
    int transferPrice;
};

