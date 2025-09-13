/*
#### Тренировочное задание по программированию: Функция EnsureEqual ####

Напишите функцию
void EnsureEqual(const string& left, const string& right);

В случае, если строка **left** не равна строке **right**, функция должна выбрасывать исключение
runtime_error с содержанием "<l> != <r>", где <l> и <r> - строки, которые хранятся в переменных
**left** и **right** соответственно.

Если **left == right**, функция должна корректно завершаться.
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