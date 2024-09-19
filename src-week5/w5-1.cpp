#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <stdexcept>
#include "date.hpp"
#include "whitedb.hpp"

void ParseLine(WhiteDB& db, std::string line) {
	std::istringstream iss(line);
	std::string command;
	iss >> command;
	if (command == "Print") {
		db.Print();
	}
	else if (command == "Add") {
		Date date;
		std::string event;
		iss >> date >> event;
		db.Add(date, event);
	}
	else if (command == "Del") {
		if (std::regex_search(line, std::regex(R"(\d-\d-\d)"))) {
			Date date;
			iss >> date;
			db.Del(date);
		}
		else {
			std::string event;
			iss >> event;
			db.Del(event);
		}
	}
	else if (command == "Find") {
		Date date;
		iss >> date;
		db.Find(date);
	}
	else
	{
		throw std::runtime_error("Cannot parse line. Exiting.");
	}
}

void AutoTest(WhiteDB& db, std::string input, std::string expected) {
	std::istringstream iss_line(input);
	std::string line;
	while (std::getline(iss_line, line))
	{
		if (line.empty()) {
			continue;
		}
		ParseLine(db, line);
	}
	std::string actual = db.GetLog();
	std::cout << "  Actual:" << std::endl << actual;
	std::cout << "  Expect:" << std::endl << expected;
	std::cout << (actual==expected? "  Test passed! :) Fa-database-tality!": "Test fail :(") << std::endl;
}

void ManualTest(WhiteDB& db) {
	std::cout << "Proceed with manual testing. Waiting for your command, master. Stop word is \"Exit\"..." << std::endl;
	bool exit = false;
	while (exit == false) {
		std::cout << "> ";
		std::string line;
		std::getline(std::cin,line);
		if (line == "Exit") { exit = true; break; }
		ParseLine(db, line);
		if (line.substr(0, 3) != "Add") { std::cout << db.GetLastLog() << std::endl; }
	}
}


void RunTestsFinal() {
	std::clog << std::endl << "----------Final boss!-----------------" << std::endl;
	WhiteDB db;
	std::string input = R"(
Add 0-1-2 event1
Add 1-2-3 event2
Find 0-1-2
Del 0-1-2
Print

Add 0-13-32 event1

)";
	std::string expected = R"(event1
Deleted 1 events
0001-02-03 event2
Month value is invalid: 13
)";
	AutoTest(db, input, expected);
	ManualTest(db);
}