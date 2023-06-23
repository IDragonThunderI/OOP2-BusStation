#include <iostream>
#include <ctime>
#include "UI.h"

int main() {
	setlocale(LC_ALL, "ru_RU");
	srand((unsigned)time(NULL));

	BusStation* station = new BusStation("���������� ���� � 1", "������ ���� ��������");
	UserInterface* ui = new UserInterface(station);
	station->randomBusGen(10);

	std::array<std::string, 5> menu = {
		"���������� �� ���������� �����",
		"������ ��������� ���������",
		"����� ���������� �������",
		"����� ���������� �������",
		"�����"
	};

	unsigned short choice = 0;
	bool exit = false;
	while (!exit) {
		std::cout << "\n*** ������� ���� ***" << std::endl;
		for (size_t i = 0; i < menu.size(); i++) {
			std::cout << i << ". " << menu.at(i) << std::endl;
		}
		choice = menuInput(menu.size() - 1);
		switch (choice) {
		case 0:
			ui->showStationInfo();
			break;
		case 1:
			ui->showBusDepot();
			break;
		case 2:
			ui->findRequiredBus();
			break;
		case 3:
			ui->findRequiredRoute();
			break;
		case 4:
			exit = true;
			break;
		}
	}

	delete station;
	delete ui;

	return 0;
}