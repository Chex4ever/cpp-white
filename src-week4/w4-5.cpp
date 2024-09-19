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
#include <format>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "w4-5.hpp"


void Test4w5stdout(std::string input_file) {
	std::ifstream input(input_file);
	float num;
	while (input >> num) {
		std::cout << std::format("{:.3f}", num) << std::endl;
	}
	input.close();
}
void RunTests4w5() {
	std::string input1_file = "src-week4/w4-5input1.txt";
	std::string input2_file = "src-week4/w4-5input2.txt";
	std::string expected1 = R"(5.000
0.346
10.400)";
	std::string expected2 = R"(3.334
3.333
3.300)";
	std::clog << "actual1:"<< std::endl;
	Test4w5stdout(input1_file);
	std::clog << "expected1:" << std::endl << expected1 << std::endl;
	std::clog << "actual2:"<< std::endl;
	Test4w5stdout(input2_file);
	std::clog << "expected2:" << std::endl << expected2 << std::endl << "  EASY!" << std::endl;
}