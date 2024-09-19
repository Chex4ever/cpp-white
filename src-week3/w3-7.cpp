/*
#### ������� �� ����������������: ����� � ������� � 3 ####
��������� ����� *Person* �� ������ ������ � ������� � 2� �������������, ����������� ������ ��� � ������� �������� ��� ��������, � ����� ��� ��� ��������. ����� �� ������ ����� ������������ �� ���������.
��� ��������� �� ���� ����, ������� ������ ���� ��������:
* ������ *GetFullName* � *GetFullNameWithHistory* ������ �������� **"No person"**;
* ������ *ChangeFirstName* � *ChangeLastName* ������ ������������ ������.
* ����� ����, ���������� �������� ������������ ��� ������, ������� �� ���� ��� ��������.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "w3-7.hpp"


Person3::Person3(std::string fn, std::string ln, int year) {
	first_name[year] = fn;
	last_name[year] = ln;
	birthyear = year;
}

void Person3::ChangeFirstName(int year, const std::string& fn) {
	first_name[year] = fn;
}
void Person3::ChangeLastName(int year, const std::string& ln) {
	last_name[year] = ln;
}
std::string Person3::CollectNames(int year, const std::map<int, std::string>& map) const{
	std::string result = "";
	std::vector<std::string> names{};
	for (const auto& rec : map) {
		if (rec.first <= year) {
			if (names.empty() || (names.back() != rec.second)) {
				names.push_back(rec.second);
			}
		}
		else {
			break;
		}
	}

	size_t size = names.size();
	if (size > 0) {
		std::reverse(names.begin(), names.end());
		result.append(names[0]);
	}
	if (size > 1) {
		result.append(" (");
		for (size_t i = 1; i < size; i++) {
			result.append(names[i]);
			if (i == size - 1) {
				result.append(")");
			}
			else {
				result.append(", ");
			}
		}
	}
	return result;
}
std::string Person3::GetFullName(int year) const{
	if (year < birthyear) {
		return "No person";
	}
	std::clog << "searching for name at year " << year << ": ";
	std::string fn = CollectNames(year, first_name);
	std::string ln = CollectNames(year, last_name);
	if (fn.empty() && ln.empty()) {
		return "Incognito";
	}
	else if (fn.empty()) {
		return (ln + " with unknown first name");
	}
	else if (ln.empty()) {
		return (fn + " with unknown last name");
	}
	return fn + " " + ln;
}
std::string Person3::GetFullNameWithHistory(int year) const{
	if (year < birthyear) {
		return "No person";
	}
	std::string fn = CollectNames(year, first_name);
	std::string ln = CollectNames(year, last_name);
	if (fn.empty() && ln.empty()) {
		return "Incognito";
	}
	else if (fn.empty()) {
		return (ln + " with unknown first name");
	}
	else if (ln.empty()) {
		return (fn + " with unknown last name");
	}
	return (fn + " " + ln);
}
void Test3w7(const std::string& expected) {
	Person3 person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	std::clog << std::endl << expected << std::endl << "  EASY!";
}
void RunTests3w7() {
	std::string expected = R"(No person
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Appolinaria (Polina) Ivanova (Sergeeva))";
	Test3w7(expected);
}