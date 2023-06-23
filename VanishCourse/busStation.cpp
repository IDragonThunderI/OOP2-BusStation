#include <iostream>
#include <ctime>
#include "busStation.h"

BusStation::BusStation(std::string name, std::string director) {
	set_stationName(name);
	set_director(director);
}

BusStation::~BusStation() {
	for (auto& bus : busDepot) {
		delete bus;
	}
}

void BusStation::set_stationName(std::string name) {
	this->stationName = name;
}

void BusStation::set_director(std::string fullName) {
	this->director = fullName;
}

const std::string BusStation::get_stationName() const {
	return this->stationName;
}

const std::string BusStation::get_director() const {
	return this->director;
}

const std::vector<Bus*> BusStation::get_busDepot() const
{
	return this->busDepot;
}

void BusStation::addBus(Bus* bus) {
	this->busDepot.emplace_back(bus);
}

void BusStation::info() const {
	for (auto& bus : busDepot) {
		bus->info();
	}
}

void BusStation::randomBusGen(int n) {
	size_t reservedBus = busDepot.size();
	for (size_t i = 0; i < n - reservedBus; i++) {
		switch (rand() % 3) {
		case 0:
			this->addBus(new CityBus(brandList.at(rand() % 3),
									 lengthList.at(rand() % 5),
									 routeList.at(rand() % 4)));
			break;
		case 1:
			this->addBus(new IntercityBus(brandList.at(rand() % 3 + 3),
										  lengthList.at(rand() % 5),
										  routeList.at(rand() % 3 + 4)));
			break;
		case 2:
			this->addBus(new TouristBus(brandList.at(rand() % 3 + 6),
										lengthList.at(rand() % 5),
										routeList.at(rand() % 3 + 7)));
			break;
		}
	}
}
