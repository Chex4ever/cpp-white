/*
#### Задание по программированию: Автобусные остановки — 2 ####

В этой задаче вам нужно присваивать номера автобусным маршрутам.
А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер
(первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута,
которому соответствует такой набор остановок.
Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).

##### Указание #####
В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, *vector*.

##### Формат ввода #####
Сначала вводится количество запросов *Q*, затем *Q* описаний запросов.

Каждый запрос представляет собой положительное количество остановок *N*, за которым следуют
разделённые пробелом *N* различных названий остановок соответствующего маршрута.
Названия остановок состоят лишь из латинских букв и символов подчёркивания.

##### Формат вывода #####
Выведите ответ на каждый запрос в отдельной строке.
Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите
**Already exists for *i***, где ***i*** — номер маршрута с таким набором остановок.
В п*/


#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include "w2-14.hpp"

void Test2w14(const std::string& input, const std::string& expected) {
	std::string log;
	std::vector<std::vector<std::string>> db;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		int stops_count;
		iss >> stops_count;
		std::vector<std::string> stops;
		for (int j = 0; j < stops_count; j++) {
			std::string stop;
			iss >> stop;
			stops.push_back(stop);
		}
		auto iter = std::find(db.begin(),db.end(),stops);
		if (iter == db.end()) {
			db.push_back(stops);
			log.append("New bus " + std::to_string(db.size())+"\n");
		}
		else {
			log.append("Already exists for " + std::to_string(iter - db.begin()+1)+"\n");
		}
	}
	log.pop_back();
	std::clog << "'" << log << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (log == expected) {
		std::clog << "Test passed :)" << std::endl;
	}
	else {
		std::clog << "Test failed :(, but i'm not sure :)" << std::endl;
	}


}
void RunTests2w14() {
	std::string input = R"(4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino)";
	std::string expected = R"(New bus 1
New bus 2
Already exists for 1
New bus 3)";
	Test2w14(input, expected);
}