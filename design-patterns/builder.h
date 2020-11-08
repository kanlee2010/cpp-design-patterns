#pragma once

enum ComponentType { COMP_A, COMP_B };

class IComponent {
public:
	virtual void Display(void) = 0;
};

class ComponentA : public IComponent {
public:
	void Display(void);
};

class ComponentB : public IComponent {
public:
	void Display(void);
};

class Builder {
public:
	IComponent* build(ComponentType compType);
};