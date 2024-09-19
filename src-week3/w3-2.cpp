/*
#### Задание по программированию: Сортировка без учёта регистра ####

##### Условие #####
В стандартном потоке дана одна строка, состоящая из числа *N* и следующих за ним *N* строк *S*. Между собой число и строки разделены пробелом.

Отсортируйте строки *S* в лексикографическом порядке по возрастанию, игнорируя регистр букв, и выведите их в стандартный поток вывода.

##### Ограничения #####

* 0 <= N <= 1000
* 1 <= |S| <= 15
* Каждая строка S[i] может состоять из следующих символов: [0-9,a-z,A-Z]
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "w3-2.hpp"

void Test3w2(const std::string& input, const std::string& expected) {
	std::string log;
	std::istringstream iss(input);
	int words_count;
	while (iss >> words_count) {
		std::vector<std::string> words;
		for (int i = 0; i < words_count; i++) {
			std::string word;
			iss >> word;
			words.push_back(word);
		}
		std::sort(words.begin(), words.end(), [](std::string a, std::string b) 
			{return std::tolower(a[0]) < std::tolower(b[0]); });
		for (int i = 0; i < words_count; i++) {
			log.append(words[i] + ((i == words_count - 1) ? "\n" : " "));
		}
	}
	log.pop_back();
	std::clog << "'" << log << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (log == expected) {
		std::clog << "  Test passed :)" << std::endl;
	}
	else {
		std::clog << "  Test failed :(, but i'm not sure :)" << std::endl;
	}
}
void RunTests3w2() {
	std::string input = R"(2 q A
3 a C b
4 Csdvsdv baADVdv d_asdAS123 Aadvdav)";
	std::string expected = R"(A q
a b C
Aadvdav baADVdv Csdvsdv d_asdAS123)";
	Test3w2(input, expected);
}