#pragma once
#include <string>
#include <list>

class Observer
{
public:
	virtual void notify(std::string& tweet) = 0;
};

class NYTimes : public Observer
{
public:
	void notify(std::string &tweet);
};

class Guardian : public Observer 
{
public:
	void notify(std::string& tweet);
};

class LeMonde : public Observer 
{
public:
	void notify(std::string& tweet);
};

class Subject {
public:
	virtual void registerObserver(Observer* o) = 0;
	virtual void notifyObservers(std::string tweet) = 0;
};

class Feed : public Subject {
private:
	std::list<Observer*> observers;

public:
	void registerObserver(Observer* o) override;
	void notifyObservers(std::string tweet) override;
	Feed() {};
	virtual ~Feed();
};