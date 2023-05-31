#include "TransferList.h"
#include <iostream>

TransferList::TransferList(Player* player, Team* sourceTeam, Team* destinationTeam, int transferPrice)
    : player(player), sourceTeam(sourceTeam), destinationTeam(destinationTeam), transferPrice(transferPrice) {}

TransferList::~TransferList() {}

void TransferList::resolveTransfer() {
    // Рассчитываем стоимость трансфера на основе трансферной цены игрока
    transferPrice = player->getTransferPrice();
    std::cout << "Игрок " << player->getFullName() << " перешел из команды "
        << sourceTeam->getName() << " в команду " << destinationTeam->getName()
        << " за " << transferPrice << " долларов" << std::endl;
}


int TransferList::getTransferPrice() const {
    return transferPrice;
}
