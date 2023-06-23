#pragma once
#include <string>
#include <array>

enum lenghtType {
	EXTRA_SMALL = 4,
	SMALL = 6,
	MEDIUM = 8,
	LARGE = 10,
	EXTRA_LARGE = 12
};

const std::array<std::string, 9> brandList = { "ГАЗ", "ЛиАЗ", "ЗиЛ", "Volgabus", "Volvo", "Isuzu", "Mercedes", "Scania", "Solaris" };
const std::array<unsigned short, 10> routeList = { 2, 13, 40, 73, 126, 310, 326, 555, 777, 999 };
const std::array<unsigned short, 5> lengthList = { EXTRA_SMALL, SMALL, MEDIUM, LARGE, EXTRA_LARGE };

class Bus {
protected:
	std::string busBrand = "";
	std::string registrationNumber = "";
	unsigned short busLength = 0;
	unsigned short busCapacity = 0;
	unsigned short routeNumber = 0;

public:
	virtual void info() const;
	virtual void set_busBrand(std::string brand);
	virtual void set_registrationNumber(std::string number);
	virtual void set_busLength(unsigned short length);
	virtual void set_routeNumber(unsigned short number);
	virtual const std::string get_busBrand() const;
	virtual const std::string get_busType() const = 0;
	virtual const std::string get_registrationNumber() const;
	virtual const unsigned short get_busLength() const;
	virtual const unsigned short get_busCapacity() const;
	virtual const unsigned short get_routeNumber() const;
	virtual std::string regNumGen() = 0;
};

class CityBus : public Bus {
private:
	std::string busType = "Городской";

public:
	CityBus(std::string brand, unsigned short lenght, unsigned short routeNumber);
	const std::string get_busType() const override;
	std::string regNumGen() override;
};

class IntercityBus : public Bus {
private:
	std::string busType = "Междугородний";

public:
	IntercityBus(std::string brand, unsigned short lenght, unsigned short routeNumber);
	const std::string get_busType() const override;
	std::string regNumGen() override;
};

class TouristBus : public Bus {
private:
	std::string busType = "Туристический";

public:
	TouristBus(std::string brand, unsigned short lenght, unsigned short routeNumber);
	const std::string get_busType() const override;
	std::string regNumGen() override;
};