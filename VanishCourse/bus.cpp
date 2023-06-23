#include <iostream>
#include <ctime>
#include "bus.h"

void Bus::info() const {
	std::cout << "+-----------------------------------+" << std::endl;
	std::cout << "| Марка автобуса: " << get_busBrand() << std::endl;
	std::cout << "| Тип автобуса: " << get_busType() << std::endl;
	std::cout << "| Регистрационный номер: " << get_registrationNumber() << std::endl;
	std::cout << "| Вместительность автобуса: " << get_busCapacity() << " мест" << std::endl;
	std::cout << "| Номер маршрута: " << get_routeNumber() << std::endl;
	std::cout << "+-----------------------------------+" << std::endl;
}

void Bus::set_busBrand(std::string brand) {
	this->busBrand = brand;
}

void Bus::set_registrationNumber(std::string number) {
	this->registrationNumber = number;
}

void Bus::set_busLength(unsigned short length) {
	this->busLength = length;
	this->busCapacity = length * 5;
}

void Bus::set_routeNumber(unsigned short number) {
	this->routeNumber = number;
}

const std::string Bus::get_busBrand() const {
	return this->busBrand;
}

const std::string Bus::get_registrationNumber() const {
	return this->registrationNumber;
}

const unsigned short Bus::get_busLength() const {
	return this->busLength;
}

const unsigned short Bus::get_busCapacity() const {
	return this->busCapacity;
}

const unsigned short Bus::get_routeNumber() const {
	return this->routeNumber;
}

CityBus::CityBus(std::string brand, unsigned short lenght, unsigned short routeNumber) {
	set_busBrand(brand);
	set_busLength(lenght);
	set_routeNumber(routeNumber);
	set_registrationNumber(this->regNumGen());
}

const std::string CityBus::get_busType() const {
	return this->busType;
}

std::string CityBus::regNumGen() {
	std::array<short, 4> buf{};
	for (short i = 0; i < 4; i++) {
		buf.at(i) = rand() % 200 + 100;
	}
	return (char)(buf.at(0) % 26 + 65) + std::to_string(buf.at(1)) + (char)(buf.at(2) % 26 + 65) + (char)(buf.at(3) % 26 + 65);
}

IntercityBus::IntercityBus(std::string brand, unsigned short lenght, unsigned short routeNumber) {
	set_busBrand(brand);
	set_busLength(lenght);
	set_routeNumber(routeNumber);
	set_registrationNumber(this->regNumGen());
}

const std::string IntercityBus::get_busType() const {
	return this->busType;
}

std::string IntercityBus::regNumGen() {
	std::array<short, 4> buf{};
	for (short i = 0; i < 4; i++) {
		buf.at(i) = rand() % 200 + 300;
	}
	return (char)(buf.at(0) % 26 + 65) + std::to_string(buf.at(1)) + (char)(buf.at(2) % 26 + 65) + (char)(buf.at(3) % 26 + 65);
}

TouristBus::TouristBus(std::string brand, unsigned short lenght, unsigned short routeNumber) {
	set_busBrand(brand);
	set_busLength(lenght);
	set_routeNumber(routeNumber);
	set_registrationNumber(this->regNumGen());
}

const std::string TouristBus::get_busType() const {
	return this->busType;
}

std::string TouristBus::regNumGen() {
	std::array<short, 4> buf{};
	for (short i = 0; i < 4; i++) {
		buf.at(i) = rand() % 500 + 500;
	}
	return (char)(buf.at(0) % 26 + 65) + std::to_string(buf.at(1)) + (char)(buf.at(2) % 26 + 65) + (char)(buf.at(3) % 26 + 65);
}
