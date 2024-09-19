#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Person1 {
public:
	void ChangeFirstName(int , const std::string&);
	void ChangeLastName(int , const std::string&);
	std::string GetFullName(int);
private:
	std::string ClosestYearValue(int year, std::map<int, std::string> map);
	std::map<int, std::string> first_name;
	std::map<int, std::string> last_name;
};

void Test3w4(const std::string& expected);
void RunTests3w4();