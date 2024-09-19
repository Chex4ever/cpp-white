/*
#### ������� �� ����������������: ���������� ��������� � 3 ####
� ���� ������ ��� ����� ����������� ������ ���������� ���������.
� ������, ��� ������� ��������, ��������� ���������� �������� ���������,
����� ���� ������ ����� ����� (������� �������� � 1, ������� � 2 � �. �.),
���� ������� ����� ������������� ��������, �������� ������������� ����� ��������� ���������.

� ������� �� ������ ����������� ��������� � 2�, ������ ���������, ������� ����� ��������
���� �� ����� ������������� ��������� ��� �����������/��������� �������������, ������� ������� �����������.

##### ������ ����� #####
������� �������� ���������� �������� *Q*, ����� *Q* �������� ��������.
������ ������ ������������ ����� ������������� ���������� ��������� *N*, �� ������� ������� ���������� �������� *N* �������� ��������� ���������������� �������� (�� ����������� ���������). �������� ��������� ������� ���� �� ��������� ���� � �������� �������������.

##### ������ ������ #####
�������� ����� �� ������ ������ � ��������� ������.
���� ������� � ������ ������� ��������� ��� ����������, � ����� �� ��������������� ������ �������� **Already exists for *i***, ��� ***i*** � ����� �������� � ����� ������� ���������. � ��������� ������ ����� �������� ��������� ������ ��������� ����� ����� ***i*** � ������� ��� � ������� **New bus *i***.
*/


#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include "w2-18.hpp"


void Test2w18(const std::string& input, const std::string& expected) {
	std::string log;
	std::vector<std::set<std::string>> db;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		int stops_count;
		iss >> stops_count;
		std::set<std::string> new_bus;
		for (int j = 0; j < stops_count; j++) {
			std::string stop;
			iss >> stop;
			new_bus.insert(stop);
		}
		int already_exists = 0;
		for (size_t j = 0, db_size = db.size(); j < db_size; j++) {
			if (db[j] == new_bus) {
				already_exists = j+1;
			}
		}
		if (already_exists>0)
		{
			log.append("Already exists for " + std::to_string(already_exists) + "\n");
		}
		else {
			db.push_back(new_bus);
			log.append("New bus " + std::to_string(db.size()) + "\n");
		}
	}
	log.pop_back();
	std::clog << "'" << log << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (log == expected) {
		std::clog << "Test passed :)" << std::endl;
	}
	else {
		std::clog << "Test failed :(, but i'm not sure :)" << std::endl;
	}
}
void RunTests2w18() {
	std::string input = R"(5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino)";
	std::string expected = R"(New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2)";
	Test2w18(input, expected);
}