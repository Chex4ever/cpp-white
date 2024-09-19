/*
#### ������� �� ����������������: ������ � ������� ####
� ���� ������� ��� ��������� �������� ��� ��������� ���������. ������ ����� - ��������� ������, 
������� ����������� � ���� � ��������������� �������.

##### ����� 1 #####
���� ��������� ������ ������� ���������� ����� *input.txt* � ���������� ��� �� ����� ��� ���������. 
�������������, ��� ���������� ����� *input.txt* ������������� ��������� ������.

##### ����� 2 #####
����� �������� ��� ���������� ����� *input.txt*, �� �� ���� ��� �������� ��� � ���� *output.txt*. 
����� ��� �� �������������, ��� ���������� ����� *input.txt* ������������� ��������� ������.

*/

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "w4-4.hpp"


void Test4w4stdout(std::string input_file) {
	std::ifstream input(input_file);
	std::string line;
	while (getline(input, line)) {
		std::cout << line << std::endl;
	}
	input.close();
}

void Test4w4ofstream(std::string input_file, std::string output_file) {
	std::ifstream input(input_file, std::ios::in);
	std::ofstream output(output_file, std::ios::out);
	std::string line;
	while (getline(input, line)) {
		output << line << std::endl;
	}
	output.close();
	input.close();
}

void RunTests4w4() {
	std::string input_file = "src-week4/w4-4input.txt";
	std::string output_file = "src-week4/w4-4output.txt";
	std::string expected = R"(Kepp calm
and
learn C++)";
	Test4w4stdout(input_file);
	Test4w4ofstream(input_file, output_file);

	std::ifstream input(output_file, std::ios::in);
	std::ostringstream actual;
	std::string line;
	while (getline(input, line)) {
		actual << line << std::endl;
	}
	input.close();
	std::clog << std::endl << actual.str() << std::endl << expected << std::endl << "  EASY!" << std::endl;
}