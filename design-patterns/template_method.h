#pragma once

enum DoorStatus { CLOSED, OPENED };
enum MotorStatus { MOVING, STOPPED };
enum Direction { UP, DOWN, LEFT, RIGHT };

class Door 
{
private:
	DoorStatus doorStatus;
public:
	Door() { doorStatus = DoorStatus::CLOSED; }
	DoorStatus getDoorStatus() { return doorStatus; }
	void close() { doorStatus = DoorStatus::CLOSED; }
	void open() { doorStatus = DoorStatus::OPENED; }
};

/* HyundaiMotor와 LGMotor의 공통적인 기능을 구현하는 클래스 */
class Motor 
{
protected:
	Door door;
private:
	MotorStatus motorStatus; // 공통 2. motorStatus 필드

public:
	Motor(Door &door) { // 공통 1. Door 클래스와의 연관관계
		this->door = door;
		motorStatus = MotorStatus::STOPPED;
	}
	// 공통 3. etMotorStatus, setMotorStatus 메서드
	MotorStatus getMotorStatus() { return motorStatus; }

	void move(Direction direction);
protected:
	void setMotorStatus(MotorStatus motorStatus) { this->motorStatus = motorStatus; }
	virtual void moveMotor(Direction direction) = 0;
};

/* Motor를 상속받아 HyundaiMotor 클래스를 구현 */
class HyundaiMotor : public Motor 
{
public:
	HyundaiMotor(Door &door) : Motor(door) { }
protected:
	void moveMotor(Direction direction);
};

/* Motor를 상속받아 LGMotor 클래스를 구현 */
class LGMotor : public Motor 
{
public:
	LGMotor(Door &door) : Motor(door) { }
protected:
	void moveMotor(Direction direction);
};
