/*
#### ������������� ������� �� ����������������: ������� EnsureEqual ####

�������� �������
void EnsureEqual(const string& left, const string& right);

� ������, ���� ������ **left** �� ����� ������ **right**, ������� ������ ����������� ����������
runtime_error � ����������� "<l> != <r>", ��� <l> � <r> - ������, ������� �������� � ����������
**left** � **right** ��������������.

���� **left == right**, ������� ������ ��������� �����������.
*/

#include <string>
#include <iostream>
#include <stdexcept>
#include "w4-9.hpp"

void EnsureEqual(const std::string& left, const std::string& right) {
	if (left != right) {
		throw std::runtime_error(left + " != " + right);
	}
}


void RunTests4w9() {
	try {
		EnsureEqual("left", "right");
	}
	catch (const std::runtime_error& e) {
		std::cerr << "I catch runtime error! Message is: "<< e.what() << std::endl;
	}
	EnsureEqual("center", "center");
	std::cout << "  Easy! ";
}