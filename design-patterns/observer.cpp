#include <iostream>
#include "observer.h"

void NYTimes::notify(std::string& tweet)
{
	if (tweet.length() && std::string::npos != tweet.find("money")) {
		std::cout << "Breaking news in NY! " + tweet << std::endl;
	}
}

void Guardian::notify(std::string& tweet)
{
	if (tweet.length() && std::string::npos != tweet.find("queen")) {
		std::cout << "Yet more news in London... " + tweet << std::endl;
	}
}

void LeMonde::notify(std::string& tweet)
{
	if (tweet.length() && std::string::npos != tweet.find("wine")) {
		std::cout << "Today cheese, wine, and news! " + tweet << std::endl;
	}
}

void Feed::registerObserver(Observer* o)
{
	observers.push_back(o);
}

void Feed::notifyObservers(std::string tweet)
{
	for (Observer *o : observers) {
		o->notify(tweet);
	}
}

Feed::~Feed()
{
	for (Observer *o : observers) {
		delete o;
	}
}

void observer_client(void)
{
	Feed f;
	//f.registerObserver(NYTimes()); // c++은 java와 같이 virtual을 overriding 구현하면서 정의할 수 있는 익명 객체 기능이 없다.
	f.registerObserver(new Guardian());
	f.registerObserver(new LeMonde());
	f.notifyObservers("The queen said her favourite book is Java 8 in Action!");
}
