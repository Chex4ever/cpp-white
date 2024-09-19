#pragma once
#include <string>
#include <vector>

class Table {
public:
	Table(int, int);
	Table(std::string);
	std::string ToString();
private:
	std::vector<std::vector<std::string>> table;
	int rows;
	int cols;
};
void RunTests4w6();