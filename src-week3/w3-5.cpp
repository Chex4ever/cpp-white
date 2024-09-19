/*
#### Задание по программированию: Имена и фамилии — 2 ####

Дополните класс из предыдущей задачи «Имена и фамилии — 1» методом *GetFullNameWithHistory*:

В отличие от метода *GetFullName*, метод *GetFullNameWithHistory* должен вернуть не только последние
имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке.
Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же,
второе изменение при формировании истории нужно игнорировать.
*/

#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "w3-5.hpp"


void Person2::ChangeFirstName(int year, const std::string& fn) {
	first_name[year] = fn;
}
void Person2::ChangeLastName(int year, const std::string& ln) {
	last_name[year] = ln;
}
std::string Person2::CollectNames(int year, std::map<int, std::string> map) {
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
std::string Person2::GetFullName(int year) {
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
std::string Person2::GetFullNameWithHistory(int year) {
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
void Test3w5(const std::string& expected) {
	Person2 person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	std::cout << person.GetFullNameWithHistory(1990) << std::endl;

	person.ChangeFirstName(1966, "Pauline");
	std::cout << person.GetFullNameWithHistory(1966) << std::endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		std::cout << person.GetFullNameWithHistory(year) << std::endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	std::cout << person.GetFullNameWithHistory(1967) << std::endl;

	std::clog << std::endl << expected << std::endl << "  EASY!";
}
void RunTests3w5() {
	std::string expected = R"(Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Polina Volkova (Sergeeva)
Appolinaria (Polina) Volkova (Sergeeva)
Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
Pauline (Polina) with unknown last name
Sergeeva with unknown first name
Pauline (Polina) Sergeeva
Pauline (Polina) Sergeeva (Ivanova, Sergeeva))";
	Test3w5(expected);
}