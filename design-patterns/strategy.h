class IStrategy
{
public:
	virtual void Display(void) = 0;
};

class StrategyImplA : public IStrategy {
public:
	void Display(void);
};

class StrategyImplB : public IStrategy {
public:
	void Display(void);
};

class StrategyContainer {
private:
	class IStrategy *m_ifstr;

public:
	StrategyContainer();
	void SetStrategy(class IStrategy *i);
	void Display(void);
};