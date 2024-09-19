/*
#### ������� �� ����������������: ������ � ����� ������� ####

� ������ ������ ����� *input.txt* �������� ��� ����� *N* � *M*.
����� � ����� ��������� ������� �� *N* ����� � *M* ��������, ��������������
� ������� *CSV (comma-separated values)*. ����� ������ ����� ������������ ���
���������� ������������� ������ � �������: � ����� ��������� �����, ��������
�� ������ ����� ������ ������ �������� ���� �� ����� ��������. ���� ������ �
������� ������ �� ����� � ���� �������, ������ ������ ������� ����� 10, ��������
������ �������� ���� �� ����� ��������. ����� ��������� ������ ������� ���� �� ������.
�������������, ��� � ������� ����� ����� *N* ����� � *M* ��������,
�������� ������ �� ����� � ����� �����.
*/

#include <string>
#include <format>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include "w4-6.hpp"

Table::Table(int r, int c) {
	std::vector<std::vector<std::string>> table(r, std::vector<std::string>(c));
	rows = r;
	cols = c;
}
Table::Table(std::string filepath) {
	std::ifstream input(filepath);
	std::string line, cell;
	input >> rows >> cols;
	std::getline(input, line);
	table.resize(rows, std::vector<std::string>(cols));
	for (int row = 0; row < rows; row++) {
		std::getline(input, line);
		std::stringstream ss(line);
		for (int col = 0; col < cols; col++) {
			std::getline(ss, table[row][col], ',');
		}
	}
	input.close();

}
std::string Table::ToString() {
	std::string result;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			result.append(std::format("{:>10}", table[row][col]) + (col == cols - 1 ? "" : " "));
		}
		if (row != rows - 1) {
			result.append("\n");
		}
	}
	return result;
}
void RunTests4w6() {
	Table table("src-week4/w4-6input.txt");
	std::string actual = table.ToString();
	std::string expected = R"(         1          2          3
         4          5          6)";
	std::clog << "actual:" << std::endl << actual << std::endl;
	std::clog << "expected:" << std::endl << expected << std::endl;
	std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << std::endl;
}