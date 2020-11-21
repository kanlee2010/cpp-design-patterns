#pragma once
class Color {
public:
	virtual void applyColor(void) = 0;
};

class RedColor : public Color {
public:
	void applyColor(void);
};

class GreenColor : public Color {
public:
	void applyColor(void);
};

class Shape{
protected:
	Color *color;
public:
	Shape(Color *color) {
		this->color = color;
	}
	virtual ~Shape() {
		if (color) delete color;
	}

	virtual void applyColor(void) = 0;
};

class Triangle : public Shape {
public:
	Triangle(Color *color):Shape(color) {
	}
	// Inherited via Shape
	virtual void applyColor(void) override;
};

class Pentagon : public Shape {
public:
	Pentagon(Color *color):Shape(color) {

	}
	// Inherited via Shape
	virtual void applyColor(void) override;
};