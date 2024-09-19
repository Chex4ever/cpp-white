/*
#### “ренировочное задание по программированию: —правочник столиц ####

–еализуйте справочник столиц стран.

Ќа вход программе поступают следующие запросы:

* **CHANGE_CAPITAL *country new_capital*** Ч изменение столицы страны ***country*** на ***new_capital***, либо добавление такой страны с такой столицей, если раньше еЄ не было.
* **RENAME *old_country_name new_country_name*** Ч переименование страны из ***old_country_name*** в ***new_country_name***.
* **ABOUT *country*** Ч вывод столицы страны ***country***.
* **DUMP** Ч вывод столиц всех стран.

##### ‘ормат ввода #####
¬ первой строке содержитс€ количество запросов *Q*, в следующих *Q* строках Ч описани€ запросов. ¬се названи€ стран и столиц состо€т лишь из латинских букв, цифр и символов подчЄркивани€.

##### ‘ормат вывода #####
¬ыведите результат обработки каждого запроса:

¬ ответ на запрос **CHANGE_CAPITAL *country* *new_capital*** выведите

* **Introduce new country *country* with capital *new_capital***, если страны ***country*** раньше не существовало;
* **Country *country* hasn't changed its capital**, если страна ***country*** до текущего момента имела столицу ***new_capital***;
* **Country *country* has changed its capital from *old_capital* to *new_capital***, если страна ***country*** до текущего момента имела столицу ***old_capital***, название которой не совпадает с названием ***new_capital***.

¬ ответ на запрос **RENAME *old_country_name* *new_country_name*** выведите

* **Incorrect rename, skip**, если новое название страны совпадает со старым, страна ***old_country_name*** не существует или страна ***new_country_name*** уже существует;
* **Country *old_country_name* with capital *capital* has been renamed to *new_country_name***, если запрос корректен и страна имеет столицу ***capital***.

¬ ответ на запрос **ABOUT *country*** выведите

* **Country *country* doesn't exist**, если страны с названием ***country*** не существует;
* **Country *country* has capital *capital***, если страна ***country*** существует и имеет столицу ***capital***.

¬ ответ на запрос **DUMP** выведите

* **There are no countries in the world**, если пока не было добавлено ни одной страны;
* разделЄнные пробелами пары ***country/capital***, описывающие столицы всех стран и упор€доченные по названию страны, если в мире уже есть хот€ бы одна страна.


*/
#include <format>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include "VectorToString.hpp"
#include "w2-12.hpp"



// — классами € баловалс€ в предыдущих задани€х, здесь дл€ разнообрази€ решение "в лоб".
void Test2w12(const std::string& input, const std::string& expected)
{
	std::string result = "";
	std::map<std::string, std::string> db{};
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	std::clog << "parsing: " << command_count << std::endl;
	for (int i = 0; i < command_count; i++) {
		if (!result.empty() && result.back() != '\n') { result += "\n"; }
		std::string command;
		iss >> command;
		//std::clog << command;
		if (command == "CHANGE_CAPITAL") {
			std::string country, new_capital;
			iss >> country >> new_capital;
			if (db.find(country) == db.end()) {
				result.append(std::format("Introduce new country {} with capital {}", country, new_capital));
				db[country] = new_capital;
			}
			else 
			{
				if (db[country] == new_capital) {
					result.append(std::format("Country {} hasn't changed its capital", country));
				}
				else {
					result.append(std::format("Country {} has changed its capital from {} to {}", country, db[country], new_capital));
					db[country] = new_capital;
				}
			}
		}
		else if (command == "RENAME") {
			std::string old_country_name, new_country_name;
			iss >> old_country_name >> new_country_name;
			if (old_country_name == new_country_name || db.find(old_country_name) == db.end() || db.find(new_country_name) != db.end()) {
				result.append("Incorrect rename, skip");
			}
			else {
				result.append(std::format("Country {} with capital {} has been renamed to {}", old_country_name, db[old_country_name], new_country_name));
				auto record = db.extract(old_country_name);
				record.key() = new_country_name;
				db.insert(std::move(record));
			}
		}
		else if (command == "ABOUT") {
			std::string country;
			iss >> country;
			if (db.find(country) == db.end()) {
				result.append(std::format("Country {} doesn't exist", country));
			}
			else {
				result.append(std::format("Country {} has capital {}", country, db[country]));
			}
		}
		else if (command == "DUMP") {
			if (db.empty()) {
				result.append("There are no countries in the world");
			}
			else {
				for (auto iter = db.begin(); iter != db.end();iter++) {
					result.append(iter->first + "/" + iter->second);
					if (std::next(iter) != db.end()) {
						result.append(" ");
					}
				}
			}
		}
		else {
			std::clog << "Unrecognized command";
		}
	}
	std::cout << "'" << result << "'" << std::endl;

	std::cout << "  Expected: " << std::endl << "'" << expected << "'" << std::endl;
	std::cout << "  Test " << ((result == expected) ? "pass :)" : "fail :(") << std::endl;
}

void RunTests2w12()
{
	std::string test_1_input = R"(6
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
ABOUT RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
DUMP)";
std::string test_1_expected = R"(Introduce new country RussianEmpire with capital Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic has capital Petrograd
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
USSR/Moscow)";
std::string test_2_input = R"(24
RENAME FakeCountry FarFarAway
ABOUT FarFarAway
DUMP
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL TsardomOfRussia Moscow
CHANGE_CAPITAL ColonialBrazil Salvador
CHANGE_CAPITAL TsardomOfRussia SaintPetersburg
RENAME TsardomOfRussia RussianEmpire
CHANGE_CAPITAL RussianEmpire Moscow
CHANGE_CAPITAL RussianEmpire SaintPetersburg
CHANGE_CAPITAL ColonialBrazil RioDeJaneiro
DUMP
RENAME ColonialBrazil EmpireOfBrazil
ABOUT RussianEmpire
RENAME EmpireOfBrazil UnitedStatesOfBrazil
CHANGE_CAPITAL RussianEmpire Petrograd
RENAME RussianEmpire RussianRepublic
RENAME RussianRepublic USSR
CHANGE_CAPITAL USSR Moscow
CHANGE_CAPITAL UnitedStatesOfBrazil Brasilia
RENAME UnitedStatesOfBrazil FederativeRepublicOfBrazil
ABOUT RussianEmpire
DUMP
RENAME USSR USSR)";
std::string test_2_expected = R"(Incorrect rename, skip
Country FarFarAway doesn't exist
There are no countries in the world
Introduce new country TsardomOfRussia with capital Moscow
Country TsardomOfRussia hasn't changed its capital
Introduce new country ColonialBrazil with capital Salvador
Country TsardomOfRussia has changed its capital from Moscow to SaintPetersburg
Country TsardomOfRussia with capital SaintPetersburg has been renamed to RussianEmpire
Country RussianEmpire has changed its capital from SaintPetersburg to Moscow
Country RussianEmpire has changed its capital from Moscow to SaintPetersburg
Country ColonialBrazil has changed its capital from Salvador to RioDeJaneiro
ColonialBrazil/RioDeJaneiro RussianEmpire/SaintPetersburg
Country ColonialBrazil with capital RioDeJaneiro has been renamed to EmpireOfBrazil
Country RussianEmpire has capital SaintPetersburg
Country EmpireOfBrazil with capital RioDeJaneiro has been renamed to UnitedStatesOfBrazil
Country RussianEmpire has changed its capital from SaintPetersburg to Petrograd
Country RussianEmpire with capital Petrograd has been renamed to RussianRepublic
Country RussianRepublic with capital Petrograd has been renamed to USSR
Country USSR has changed its capital from Petrograd to Moscow
Country UnitedStatesOfBrazil has changed its capital from RioDeJaneiro to Brasilia
Country UnitedStatesOfBrazil with capital Brasilia has been renamed to FederativeRepublicOfBrazil
Country RussianEmpire doesn't exist
FederativeRepublicOfBrazil/Brasilia USSR/Moscow
Incorrect rename, skip)";
Test2w12(test_1_input, test_1_expected);
Test2w12(test_2_input, test_2_expected);
}