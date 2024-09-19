#pragma once
#include <string>
#include <vector>

class SortedStrings {
public:
	void AddString(const std::string& s);
	std::vector<std::string> GetSortedStrings();
private:
	std::vector<std::string> db;
	bool sorted;
};

void PrintSortedStrings(SortedStrings& strings);
void Test3w3(const std::string& input, const std::string& expected);
void RunTests3w3();