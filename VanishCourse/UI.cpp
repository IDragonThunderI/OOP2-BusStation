#include <iostream>
#include <set>
#include "UI.h"

UserInterface::UserInterface(BusStation* busStation) {
    this->busStation = busStation;
}

void UserInterface::showStationInfo() const {
    std::cout << "\n*** ���������� �� ���������� ����� ***" << std::endl;
    std::cout << "�������� ����������� �����: " << busStation->get_stationName() << std::endl;
    std::cout << "��� ��������� ����������� �����: " << busStation->get_director() << std::endl;
    system("pause");
}

void UserInterface::showBusDepot() const {
    std::cout << "\n������ ��������� ���������: " << std::endl;
    busStation->info();
    system("pause");
}

void UserInterface::findRequiredBus() const {
    std::cout << "\n*** ����� ����������� �������� ***" << std::endl;
    std::array<std::string, 4> menu = { "���������", "�������������", "�������������", "��������� � ����" };

    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "�������� ��� ��������: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == 3) {
        return;
    }

    std::cout << "\n������ ���������� ���������: " << std::endl;
    for (auto& bus : busStation->get_busDepot()) {
        if (bus->get_busType() == menu.at(choice)) {
            bus->info();
        }
    }
    system("pause");
}

void UserInterface::findRequiredRoute() const {
    std::cout << "\n*** ����� ����������� �������� ***" << std::endl;
    std::array<std::string, 4> menu = { "���������", "�������������", "�������������", "��������� � ����" };
    std::set<unsigned short> buf{};

    for (size_t i = 0; i < menu.size(); i++) {
        std::cout << i << ". " << menu.at(i) << std::endl;
    }

    std::cout << "�������� ��� ��������: ";
    unsigned short choice = menuInput(menu.size() - 1);

    if (choice == 3) {
        return;
    }

    std::cout << "\n������ ���������� ���������: " << std::endl;
    for (auto& bus : busStation->get_busDepot()) {
        if (bus->get_busType() == menu.at(choice)) {
            buf.insert(bus->get_routeNumber());
        }
    }
    for (auto& i : buf) {
        std::cout << "� " << i << std::endl;
    }
    system("pause");
}

unsigned short menuInput(size_t numberOfItems) {
    short choice = 0;
    while (true) {
        try {
            if (!(std::cin >> choice) or choice > numberOfItems) {
                throw std::invalid_argument("������������ �������� ���������");
            }
            return choice;
        }
        catch (const std::invalid_argument& error) {
            std::cerr << "������: " << error.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
