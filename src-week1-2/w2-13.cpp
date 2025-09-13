/*
#### Задание по программированию : Автобусные остановки — 1 ####
Реализуйте систему хранения автобусных маршрутов.Вам нужно обрабатывать следующие запросы :

***NEW_BUS * bus stop_count stop1 stop2 ...***— добавить маршрут автобуса с названием
* **bus * **и * **stop_count * **остановками с названиями * **stop1, stop2, ...***
*** BUSES_FOR_STOP* stop*** — вывести названия всех маршрутов автобуса, проходящих через остановку*** stop*** .
*** STOPS_FOR_BUS* bus*** — вывести названия всех остановок маршрута*** bus*** со списком автобусов,
на которые можно пересесть на каждой из остановок.
*** ALL_BUSES** — вывести список всех маршрутов с остановками.

##### Формат ввода #####
В первой строке ввода содержится количество запросов* Q*, затем в* Q* строках следуют описания запросов.
Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.
Для каждого запроса** NEW_BUS* bus stop_count stop1 stop2 ...*** гарантируется, что маршрут*** bus*** отсутствует,
количество остановок больше 0, а после числа*** stop_count*** следует именно такое количество названий остановок,
причём все названия в каждом списке различны.

##### Формат вывода #####
Для каждого запроса, кроме** NEW_BUS**, выведите соответствующий ответ на него :

*На запрос** BUSES_FOR_STOP* stop*** выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке,
в котором они создавались командами** NEW_BUS** .Если остановка*** stop*** не существует, выведите** No stop** .
* На запрос** STOPS_FOR_BUS* bus*** выведите описания остановок маршрута*** bus*** в отдельных строках в том порядке,
в котором они были заданы в соответствующей команде** NEW_BUS** .Описание каждой остановки*** stop*** должно иметь вид
** Stop* stop: bus1 bus2 ...***, где*** bus1 bus2 ...*** — список автобусов, проезжающих через остановку*** stop***, в порядке,
в котором они создавались командами** NEW_BUS**, за исключением исходного маршрута*** bus*** .Если через остановку*** stop***
не проезжает ни один автобус, кроме*** bus***, вместо списка автобусов для неё выведите** no interchange** .
Если маршрут*** bus*** не существует, выведите** No bus** .
* На запрос** ALL_BUSES** выведите описания всех автобусов в алфавитном порядке.Описание каждого маршрута*** bus***
должно иметь вид** Bus* bus : stop1 stop2 ...***, где*** stop1 stop2 ...*** — список остановок автобуса*** bus*** в порядке,
в котором они были заданы в соответствующей команде** NEW_BUS** .Если автобусы отсутствуют, выведите** No buses** .
*/


#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <sstream>
#include "w2-13.hpp"


BusManager::BusManager() {
	db.clear();
	log = "";
}

std::string BusManager::GetLogs() {
	if(log.back()=='\n')
		log.pop_back();
	return log;
}
void BusManager::NewBus(std::string name, std::vector<std::string> stops) {
	Bus bus;
	bus.name = name;
	bus.stops = stops;
	db.push_back(bus);
}

std::vector<std::string> BusManager::CollectBusesForStop(std::string stop){
	std::vector<std::string> buses{};
	for (const Bus& bus : db) {
		if (std::find(bus.stops.begin(), bus.stops.end(), stop) != bus.stops.end()) {
			buses.push_back(bus.name);
		}
	}
	return buses;
}

void BusManager::BusesForStop(std::string stop) {
	std::vector<std::string> buses=CollectBusesForStop(stop);
	if (buses.empty()){
		log.append("No stop\n");
	}
	else {
		for (size_t i=0, size = buses.size(); i<size;i++){
			log.append(buses[i]);
			if (i == size - 1) {
				log.append("\n");
			}
			else {
				log.append(" ");
			}
		}
	}
}
void BusManager::StopsForBus(std::string bus) {
	auto iter_bus = std::find_if(db.begin(), db.end(), [bus](const Bus a) {return a.name==bus; });
	if (iter_bus == db.end()) {
		log.append("No bus\n");
	}
	else
	{
		const auto stops = iter_bus->stops;
		for (size_t i = 0, size = stops.size(); i < size; i++) {
			log.append("Stop "+(stops[i]) + ": ");
			std::vector<std::string> buses = CollectBusesForStop(stops[i]);
			buses.erase(std::find(buses.begin(), buses.end(), bus));
			if (buses.empty()) {
				log.append("no interchange\n");
			} else
			{
				for (size_t j = 0, buses_size = buses.size(); j < buses.size(); j++) {
					log.append(buses[j]);
					if (j == buses_size - 1) {
						log.append("\n");
					}
					else {
						log.append(" ");
					}
				}
			}
		}
	}
}
void BusManager::AllBuses() {
	if (db.empty()) {
		log.append("No buses\n");
	}
	else
	{
		auto& tmp = db;
		std::sort(tmp.begin(), tmp.end(), [](Bus a, Bus b) {return a.name < b.name; });
		for (size_t i = 0, size = tmp.size(); i < size; i++) {
			log.append("Bus " + tmp[i].name + ": ");
			for (size_t j = 0, stops = tmp[i].stops.size(); j < stops; j++) {
				log.append(tmp[i].stops[j]);
				if (j == stops - 1) {
					log.append("\n");
				}
				else {
					log.append(" ");
				}
			}
		}
	}
}

void Test2w13(const std::string& input, const std::string& expected) {
	BusManager bm;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		std::string command;
		iss >> command;
		if (command == "NEW_BUS") {
			std::string bus_name;
			int stops_count;
			std::vector<std::string> stops;
			iss >> bus_name >> stops_count;
			std::string stop_name;
			for (int i = 0; i < stops_count; i++) {
				iss >> stop_name;
				stops.push_back(stop_name);
			}
			bm.NewBus(bus_name, stops);
		}
		else if (command == "BUSES_FOR_STOP") {
			std::string stop_name;
			iss >> stop_name;
			bm.BusesForStop(stop_name);
		}
		else if (command == "STOPS_FOR_BUS") {
			std::string bus_name;
			iss >> bus_name;
			bm.StopsForBus(bus_name);
		}
		else if (command == "ALL_BUSES") {
			bm.AllBuses();
		}
		else {
			std::clog << "Unrecognized command";
		}
	}
	std::clog << "'" << bm.GetLogs() << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (bm.GetLogs() == expected) {
		std::clog << "Test passed :)" << std::endl;
	}
	else {
		std::clog << "Test failed :(, but i'm not sure :)" << std::endl;
	}

}
void RunTests2w13() {
	std::string input = R"(10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES)";
	std::string expected = R"(No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo)";
	Test2w13(input, expected);
}