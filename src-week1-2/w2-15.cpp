/*
#### ������������� ������� �� ����������������: ���������� ���������� ����� ####

��� ����� �����. ������� ���������� ���������� ����� � ���� ������.

##### ������ ����� #####
������� �������� ���������� ����� *N*, ����� � ���� *N* �����, ���������� ��������. ��� ������ ������� ���� �� ��������� ����, ���� � �������� �������������.

##### ������ ������ #####
�������� ������������ ����� ����� � ���������� ���������� ����� � ������ ������.
*/


#include <string>
#include <set>
#include <iostream>
#include <sstream>
#include "w2-15.hpp"

void Test2w15(const std::string& input, const std::string& expected) {
	std::set<std::string> db;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		std::string record;
		iss >> record;
		db.insert(record);
	}
	std::string actual = std::to_string(db.size());
	std::clog << "'" << actual << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (actual == expected) {
		std::clog << "Test passed :)" << std::endl;
	}
	else {
		std::clog << "Test failed :(, but i'm not sure :)" << std::endl;
	}


}
void RunTests2w15() {
	std::string input = R"(6
first
second
first
third
second
second)";
	std::string expected = R"(3)";
	Test2w15(input, expected);
}