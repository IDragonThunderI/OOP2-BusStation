#pragma once
#include <vector>
#include "bus.h"

class BusStation {
private:
	std::string stationName = "";
	std::string director = "";
	std::vector<Bus*> busDepot = {
		new CityBus(brandList.at(rand() % 3),
					lengthList.at(rand() % 5),
					routeList.at(rand() % 4)),

		new IntercityBus(brandList.at(rand() % 3 + 3),
						 lengthList.at(rand() % 5),
						 routeList.at(rand() % 3 + 4)),

		new TouristBus(brandList.at(rand() % 3 + 6),
					   lengthList.at(rand() % 5),
					   routeList.at(rand() % 3 + 7))
	};
	
public:
	BusStation(std::string name, std::string director);
	~BusStation();

	void set_stationName(std::string name);
	void set_director(std::string fullName);
	const std::string get_stationName() const;
	const std::string get_director() const;
	const std::vector<Bus*> get_busDepot() const;

	void addBus(Bus* bus);
	void info() const;
	void randomBusGen(int count);
};