#pragma once
#include "busStation.h"

class UserInterface {
private:
	BusStation* busStation = nullptr;

public:
	UserInterface(BusStation* busStation);

	void showStationInfo() const;
	void showBusDepot() const;
	void findRequiredBus() const;
	void findRequiredRoute() const;
};

unsigned short menuInput(size_t numberOfItems);