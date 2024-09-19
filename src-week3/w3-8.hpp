#pragma once

#include <vector>
#include <initializer_list>

class Incognizable {
public:
	Incognizable() = default;
	Incognizable(std::initializer_list<int> args) : db(args) {};
	std::string ToString() const;
	int Size() const;
private:
	std::vector<int> db;
};

void RunTests3w8();