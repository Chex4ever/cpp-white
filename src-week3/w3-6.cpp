/*
#### Тренировочное задание по программированию: Строка ####

Реализуйте класс *ReversibleString*, хранящий строку и поддерживающий методы *Reverse*
для переворота строки и *ToString* для получения строки.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "w3-6.hpp"

ReversibleString::ReversibleString(std::string string) {
	this -> string = string;
}
ReversibleString::ReversibleString() {
	string.clear();
}

void ReversibleString::Reverse() {
	std::reverse(string.begin(), string.end());

}
std::string ReversibleString::ToString() const {
	return string;
}

void Test3w6(const std::string& expected) {
	ReversibleString s("live");
	s.Reverse();
	std::cout << s.ToString() << std::endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	std::cout << tmp << std::endl;

	ReversibleString empty;
	std::cout << '"' << empty.ToString() << '"' << std::endl;

	std::clog << expected << std::endl << "  EASY!";
}
void RunTests3w6() {
	std::string expected = R"(evil
live
"")";
	Test3w6(expected);
}