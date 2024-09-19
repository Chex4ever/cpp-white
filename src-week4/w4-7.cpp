/*
#### Тренировочное задание по программированию: Список студентов ####

Определите структуру "Студент" с полями имя, фамилия, дата, месяц и год рождения.
Создайте вектор из таких структур, заполните его из входных данных и затем по запросам выведите нужные поля.
*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "w4-7.hpp"

std::string ParseInput(std::vector<Student>& students, const std::string& input) {
	std::string result;
	std::istringstream iss(input);
	int command_count;
	for(iss >> command_count; command_count >0; --command_count)
	{
		std::string name, surname;
		int day, month, year;
		iss >> name >> surname >> day >> month >> year;
		students.push_back({ name, surname,day,month,year });
	}
	for (iss >> command_count; command_count > 0; --command_count) {
		std::string command;
		int index;
		iss >> command >> index;
		--index;
		if (command == "name") {
			result.append(students[index].first_name + " " + students[index].last_name + "\n");
		}
		else if (command == "date") {
			result.append(std::to_string(students[index].birthday.day) + '.'
				+ std::to_string(students[index].birthday.month) + '.'
				+ std::to_string(students[index].birthday.year) + '\n');
		}
		else {
			result.append("bad request\n");
		}

	}
	result.pop_back();
	return result;
}

void RunTests4w7() {
	std::vector<Student> students;

	std::string input = R"(3
Ivan Ivanov 1 1 1901
Petr Petrox 2 2 1902
Alexander Sidorov 3 3 1903
3
name 1
date 3
mark 5)";
	std::string expected = R"(Ivan Ivanov
3.3.1903
bad request)";
	std::string actual = ParseInput(students,input);
	std::clog << "actual:" << std::endl << actual << std::endl;
	std::clog << "expected:" << std::endl << expected << std::endl;
	std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << std::endl;
}