/*
#### ������� �� ����������������: ���������� � ������ Rational ####

�������� ����� *Rational*, ������� �� ����������� � �������, ����������� ���������� ����������.
��� ���������� ����������, ��� � ������ ������� ������ *Rational* ������� �� ��������� �
������� ������������ � ������� �� ����������� ������� �� ����. ������� ����� ����������
�� ����� ����������� � ��������� ������������ ������� ����������� � ������� �� ����.
� ���� ������ ��� ��������� ��� �������.

��������� ���������� ������������ ������ *Rational* ���, ����� �� ���������� ����������
*invalid_argument*, ���� ����������� ����� ����. ����� ����, ����������� ���������� ���������
������� ��� ������ *Rational* ���, ����� �� ���������� ���������� *domain_error*,
���� �������� ����� ����.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "w4-10.hpp"
#include "rational.hpp"


void RunTests4w10() {


	std::cout << " Test 1: rational (1,0)" << std::endl;
	try{
		Rational test1(1, 0);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << " Test 2: Rational (1,1) / 0" << std::endl;
	try{
		Rational test2(1, 1);
		Rational subzero = test2 / 0;
	}
	catch (std::domain_error& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "  Easy! ";
}