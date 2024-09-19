/*
#### Задание по программированию: Автобусные остановки — 3 ####
В этой задаче вам нужно присваивать номера автобусным маршрутам.
А именно, для каждого маршрута, заданного множеством названий остановок,
нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.),
либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить
друг из друга перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.

##### Формат ввода #####
Сначала вводится количество запросов *Q*, затем *Q* описаний запросов.
Каждый запрос представляет собой положительное количество остановок *N*, за которым следуют разделённые пробелом *N* названий остановок соответствующего маршрута (не обязательно различных). Названия остановок состоят лишь из латинских букв и символов подчёркивания.

##### Формат вывода #####
Выведите ответ на каждый запрос в отдельной строке.
Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите **Already exists for *i***, где ***i*** — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер ***i*** и вывести его в формате **New bus *i***.
*/


#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <sstream>
#include "w2-18.hpp"


void Test2w18(const std::string& input, const std::string& expected) {
	std::string log;
	std::vector<std::set<std::string>> db;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		int stops_count;
		iss >> stops_count;
		std::set<std::string> new_bus;
		for (int j = 0; j < stops_count; j++) {
			std::string stop;
			iss >> stop;
			new_bus.insert(stop);
		}
		int already_exists = 0;
		for (size_t j = 0, db_size = db.size(); j < db_size; j++) {
			if (db[j] == new_bus) {
				already_exists = j+1;
			}
		}
		if (already_exists>0)
		{
			log.append("Already exists for " + std::to_string(already_exists) + "\n");
		}
		else {
			db.push_back(new_bus);
			log.append("New bus " + std::to_string(db.size()) + "\n");
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
void RunTests2w18() {
	std::string input = R"(5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino)";
	std::string expected = R"(New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2)";
	Test2w18(input, expected);
}