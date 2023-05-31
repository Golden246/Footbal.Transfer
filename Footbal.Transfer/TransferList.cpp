#include "TransferList.h"
#include <iostream>

TransferList::TransferList(Player* player, Team* sourceTeam, Team* destinationTeam, int transferPrice)
    : player(player), sourceTeam(sourceTeam), destinationTeam(destinationTeam), transferPrice(transferPrice) {}

TransferList::~TransferList() {}

void TransferList::resolveTransfer() {
    // ������������ ��������� ��������� �� ������ ����������� ���� ������
    transferPrice = player->getTransferPrice();
    std::cout << "����� " << player->getFullName() << " ������� �� ������� "
        << sourceTeam->getName() << " � ������� " << destinationTeam->getName()
        << " �� " << transferPrice << " ��������" << std::endl;
}


int TransferList::getTransferPrice() const {
    return transferPrice;
}
