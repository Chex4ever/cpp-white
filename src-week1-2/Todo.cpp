#include <vector>
#include <string>
#include "Todo.hpp"

int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
Todo::Todo() {
	db.clear();
	current_month = 1;
}
void Todo::Add(int day, std::string name) {
	db.push_back(TodoRecord{ day, name });
}
std::string Todo::Dump(int day) {
	std::string result = "";
	int count{ 0 };
	for (const auto& record : db) {
		if (record.day == day) {
			result.append(record.name+ " ");
			count++;
		}
	}
	return std::to_string(count) + " " + result;
}
void Todo::Next() {
	current_month++;
	int days_in_current_month = days_in_month[current_month-1];
	for (auto& record : db) {
		if (record.day > days_in_current_month) {
			record.day = days_in_current_month;
		}
}
}