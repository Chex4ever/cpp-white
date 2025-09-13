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