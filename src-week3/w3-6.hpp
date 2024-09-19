#pragma once

#include <algorithm>
#include <string>
#include <vector>

class ReversibleString {
public:
	ReversibleString();
	ReversibleString(std::string);
	void Reverse();
	std::string ToString() const;
private:
	std::string string;
};

void Test3w6(const std::string& expected);
void RunTests3w6();