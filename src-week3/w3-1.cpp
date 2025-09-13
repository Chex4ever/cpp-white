/*
#### Задание по программированию: Сортировка целых чисел по модулю ####

##### Условие #####
В стандартном потоке дана одна строка, состоящая из *N + 1* целых чисел.
Первым числом идёт само число *N*. Далее следуют ещё *N* чисел, обозначим их за массив *A*.
Между собой числа разделены пробелом.

Отсортируйте массив *А* по модулю и выведите его в стандартный поток.

##### Ограничения #####
* 0 <= N <= 1000
* -1000000 <= A[i] <= 1000000

##### Пример #####
|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 2 -4 3                         | 3 -4                           |
| 3 1 -3 2                       | 1 2 -3                         |
*/


#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "w3-1.hpp"


void Test3w1(const std::string& input, const std::string& expected) {
	std::string log;
	std::istringstream iss(input);
	int nums_count;
	while(iss >> nums_count){
		std::vector<int> nums;
		for (int i = 0; i < nums_count; i++) {
			int num;
			iss >> num;
			nums.push_back(num);
		}
		std::sort(nums.begin(), nums.end(), [](int a, int b) {return std::abs(a) < std::abs(b); });
		for (int i = 0; i < nums_count; i++) {
			log.append(std::to_string(nums[i]) + ((i == nums_count - 1)?"\n":" "));
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
void RunTests3w1() {
	std::string input = R"(2 -4 3
3 1 -3 2)";
	std::string expected = R"(3 -4
1 2 -3)";
	Test3w1(input, expected);
}