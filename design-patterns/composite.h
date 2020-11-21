#include <vector>

#pragma once

class ComputerDevice
{
public:
	virtual int getPrice(void) const = 0;
	virtual int getPower(void) const = 0;
};

class Keyboard : public ComputerDevice {
private:
	int price;
	int power;
public:
	Keyboard(int price, int power) {
		this->price = price;
		this->power = power;
	}

	// Inherited via ComputerDevice
	virtual int getPrice(void) const override;

	virtual int getPower(void) const override;

};

class Monitor : public ComputerDevice {
private:
	int price;
	int power;
public:
	Monitor(int price, int power) {
		this->price = price;
		this->power = power;
	}

	// Inherited via ComputerDevice
	virtual int getPrice(void) const override;

	virtual int getPower(void) const override;

};

class Computer : public ComputerDevice {
private:
	std::vector<ComputerDevice*> components;

public:
	void addComponent(ComputerDevice *device) {
		components.push_back(device);
	}
	void removeComponent(ComputerDevice *device) {
		//components.erase(device);
	}

	// Inherited via ComputerDevice
	virtual int getPrice(void) const override;
	virtual int getPower(void) const override;
};