#include <iostream>
#include "template_method.h"

// HyundaiMotor와 LGMotor의 move 메서드에서 공통되는 부분만을 가짐
void Motor::move(Direction direction) {
	MotorStatus motorStatus = getMotorStatus();
	// 이미 이동 중이면 아무 작업을 하지 않음
	if (motorStatus == MotorStatus::MOVING) return;

	DoorStatus doorStatus = door.getDoorStatus();
	// 만약 문이 열려 있으면 우선 문을 닫음
	if (doorStatus == DoorStatus::OPENED) door.close();

	// 모터를 주어진 방향으로 이동시킴
	moveMotor(direction); // (HyundaiMotor와 LGMotor에서 오버라이드 됨)
	// 모터 상태를 이동 중으로 변경함
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
	hyundaiMotor.move(Direction::UP); // 위로 올라가도록 엘리베이터 제어
}