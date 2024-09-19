#pragma once
#include <string>
#include <vector>

struct Bus {
	std::string name;
	std::vector<std::string> stops;
};

class BusManager {
private:
	std::vector<Bus> db;
	std::string log;
	std::vector<std::string> CollectBusesForStop(std::string);
public:
	BusManager();
	void NewBus(std::string, std::vector<std::string>);
	void BusesForStop(std::string);
	void StopsForBus(std::string);
	void AllBuses();
	std::string GetLogs();
};

void Test2w13(const std::string& input, const std::string& expected);
void RunTests2w13();