/*
#### Задание по программированию: Имена и фамилии — 1 ####

Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.

Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени.
При этом с течением времени могут открываться всё новые факты из прошлого человека,
поэтому года́ в последовательных вызовах методов *ChangeLastName* и *ChangeFirstName* не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом *GetFullName*, должна содержать разделённые одним пробелом
имя и фамилию человека по состоянию на конец данного года.

* Если к данному году не случилось ни одного изменения фамилии и имени, верните строку **"Incognito"**.
* Если к данному году случилось изменение фамилии, но не было ни одного изменения имени,
	верните **"last_name with unknown first name"**.
* Если к данному году случилось изменение имени, но не было ни одного изменения фамилии,
	верните **"first_name with unknown last name"**.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "w3-4.hpp"

void Person1::ChangeFirstName(int year, const std::string& fn) {
	first_name[year] = fn;
}
void Person1::ChangeLastName(int year, const std::string& ln) {
	last_name[year] = ln;
}
std::string Person1::ClosestYearValue(int year, std::map<int, std::string> map) {
	int closest_year=0;
	for (const auto& rec : map) {
		if (rec.first <= year) {
			//std::clog << rec.first << "-try more, ";
			closest_year = rec.first;
		}
		else {
			//std::clog << rec.first << "-brake. ";
			break;
		}
	}
	//std::clog << iter->second << std::endl;
	if (closest_year == 0) { return "-"; }
		
	std::string result = map.find(closest_year)->second;
	return result;
}
std::string Person1::GetFullName(int year) {
	std::string fn = ClosestYearValue(year, first_name);
	std::string ln = ClosestYearValue(year, last_name);
	if (fn == "-" && ln == "-") {
		return "Incognito";
	}
	else if (fn == "-") {
		return (ln + " with unknown first name");
	}
	else if (ln == "-") {
		return (fn + " with unknown last name");
	}
	return fn + " " + ln;
}
void Test3w4(const std::string& expected) {
	Person1 person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullName(year) << std::endl;
	}

	std::clog << std::endl << expected << std::endl << "  EASY!";
}
void RunTests3w4() {
	std::string expected = R"(Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova)";
	Test3w4(expected);
}