#pragma once

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>

class Person3 {
public:
	Person3(std::string, std::string, int);
	void ChangeFirstName(int, const std::string&);
	void ChangeLastName(int, const std::string&);
	std::string GetFullName(int) const;
	std::string GetFullNameWithHistory(int) const;
private:
	std::string CollectNames(int year, const std::map<int, std::string>& map) const;
	std::map<int, std::string> first_name;
	std::map<int, std::string> last_name;
	int birthyear;
};

void Test3w7(const std::string& expected);
void RunTests3w7();