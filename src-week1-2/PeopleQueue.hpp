#pragma once
#include <vector>

class PeopleQueue {
private:
	std::vector<int> queue;
	int worried;
public:
	PeopleQueue();
	void Come(int);
	void Worry(int);
	void Quiet(int);
	int WorryCount();
};