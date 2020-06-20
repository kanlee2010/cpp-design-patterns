#pragma once
class Math {
public:
	double twoTime(double num) {
		return num * 2;
	}
	double half(double num) {
		return num / 2;
	}
};

class IAdaptor {
public:
	virtual float twiceOf(float f) = 0;
	virtual float halfOf(float f) = 0;
};

class AdaptorImpl : public IAdaptor {
	Math math;
public:
	float twiceOf(float f) override {
		return (float)math.twoTime((double)f);
	}

	float halfOf(float f) override {
		return (float)math.half((double)f);
	}
};