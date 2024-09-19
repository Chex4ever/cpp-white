/*
#### Задание по программированию: Работа с файлами ####
В этом задании вам предстоит написать две небольшие программы. Каждый пункт - отдельная задача,
решение отправляйте в поле с соответствующим номером.

##### Часть 1 #####
Ваша программа должна считать содержимое файла *input.txt* и напечатать его на экран без изменений.
Гарантируется, что содержимое файла *input.txt* заканчивается переводом строки.

##### Часть 2 #####
Снова считайте все содержимое файла *input.txt*, но на этот раз выведите его в файл *output.txt*.
Точно так же гарантируется, что содержимое файла *input.txt* заканчивается переводом строки.

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