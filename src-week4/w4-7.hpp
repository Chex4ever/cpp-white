#pragma once

#include <string>
#include <vector>

struct Date {
	int day;
	int month;
	int year;
};

struct Student {
	Student(std::string fn, std::string ln, int d, int m, int y) {
		first_name = fn;
		last_name = ln;
		birthday.day = d;
		birthday.month = m;
		birthday.year = y;
	}
	std::string first_name;
	std::string last_name;
	Date birthday;
};

std::string ParseInput(std::vector<Student>& students, const std::string& input);
void RunTests4w7();