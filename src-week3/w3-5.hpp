#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Person2{
public:
	void ChangeFirstName(int, const std::string&);
	void ChangeLastName(int, const std::string&);
	std::string GetFullName(int);
	std::string GetFullNameWithHistory(int);
private:
	std::string CollectNames(int year, std::map<int, std::string> map);
	std::map<int, std::string> first_name;
	std::map<int, std::string> last_name;
};

void Test3w5(const std::string& expected);
void RunTests3w5();