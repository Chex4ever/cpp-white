/*
#### Тренировочное задание по программированию: Отсортированные строки ####

Реализуйте класс, поддерживающий набор строк в отсортированном порядке. 
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "w3-3.hpp"

void SortedStrings::AddString(const std::string& s) {
	db.push_back(s);
	sorted = false;
}
std::vector<std::string> SortedStrings::GetSortedStrings() {
	if(!sorted){
		std::sort(db.begin(), db.end());
		sorted = true;
	}
	return db;
}

void PrintSortedStrings(SortedStrings& strings) {
	for (const std::string& s : strings.GetSortedStrings()) {
		std::cout << s << " ";
	}
	std::cout << std::endl;
}

void Test3w3(const std::string& expected) {
	SortedStrings strings;

	strings.AddString("first");
	strings.AddString("third");
	strings.AddString("second");
	PrintSortedStrings(strings);

	strings.AddString("second");
	PrintSortedStrings(strings);

	std::clog << expected << std::endl << "  EASY!";
}
void RunTests3w3() {
	std::string expected = R"(first second third
first second second third)";
	Test3w3(expected);
}