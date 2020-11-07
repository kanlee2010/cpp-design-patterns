#include <iostream>
#include "template_method.h"

// HyundaiMotor�� LGMotor�� move �޼��忡�� ����Ǵ� �κи��� ����
void Motor::move(Direction direction) {
	MotorStatus motorStatus = getMotorStatus();
	// �̹� �̵� ���̸� �ƹ� �۾��� ���� ����
	if (motorStatus == MotorStatus::MOVING) return;

	DoorStatus doorStatus = door.getDoorStatus();
	// ���� ���� ���� ������ �켱 ���� ����
	if (doorStatus == DoorStatus::OPENED) door.close();

	// ���͸� �־��� �������� �̵���Ŵ
	moveMotor(direction); // (HyundaiMotor�� LGMotor���� �������̵� ��)
	// ���� ���¸� �̵� ������ ������
	setMotorStatus(MotorStatus::MOVING);
}

void HyundaiMotor::moveMotor(Direction direction)
{
	std::cout << "HyundaiMotor::moveMotor\n";
}

void LGMotor::moveMotor(Direction direction)
{
	std::cout << "LGMotor::moveMotor\n";
}

void template_method_client(void)
{
	Door door;
	HyundaiMotor hyundaiMotor(door);
	hyundaiMotor.move(Direction::UP); // ���� �ö󰡵��� ���������� ����
}