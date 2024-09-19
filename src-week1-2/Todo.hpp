#pragma once
#include <vector>
#include <string>
struct TodoRecord {
	int day;
	std::string name;
};

class Todo {
private:
	std::vector<TodoRecord> db;
	int current_month;
public:
	Todo();
	void Add(int, std::string);
	std::string Dump(int);
	void Next();
};