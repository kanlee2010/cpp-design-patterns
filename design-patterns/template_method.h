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

/* HyundaiMotor�� LGMotor�� �������� ����� �����ϴ� Ŭ���� */
class Motor 
{
protected:
	Door door;
private:
	MotorStatus motorStatus; // ���� 2. motorStatus �ʵ�

public:
	Motor(Door &door) { // ���� 1. Door Ŭ�������� ��������
		this->door = door;
		motorStatus = MotorStatus::STOPPED;
	}
	// ���� 3. etMotorStatus, setMotorStatus �޼���
	MotorStatus getMotorStatus() { return motorStatus; }

	void move(Direction direction);
protected:
	void setMotorStatus(MotorStatus motorStatus) { this->motorStatus = motorStatus; }
	virtual void moveMotor(Direction direction) = 0;
};

/* Motor�� ��ӹ޾� HyundaiMotor Ŭ������ ���� */
class HyundaiMotor : public Motor 
{
public:
	HyundaiMotor(Door &door) : Motor(door) { }
protected:
	void moveMotor(Direction direction);
};

/* Motor�� ��ӹ޾� LGMotor Ŭ������ ���� */
class LGMotor : public Motor 
{
public:
	LGMotor(Door &door) : Motor(door) { }
protected:
	void moveMotor(Direction direction);
};
