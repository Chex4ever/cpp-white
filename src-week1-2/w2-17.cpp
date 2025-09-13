/*
#### «адание по программированию: —инонимы ####

ƒва слова называютс€ *синонимами* друг друга, если они имеют похожие значени€. –еализуйте следующие операции над словарЄм синонимов:

* **ADD *word1* *word2*** Ч добавить в словарь пару синонимов (***word1, word2***).
* **COUNT *word*** Ч узнать количество синонимов слова ***word***.
* **CHECK *word1* *word2*** Ч проверить, €вл€ютс€ ли слова ***word1*** и ***word2*** синонимами.
 —лова ***word1*** и ***word2*** считаютс€ синонимами, если среди запросов **ADD** был хот€ бы один запрос
 **ADD *word1 word2*** или **ADD *word2 word1***.

##### ‘ормат ввода #####
—начала вводитс€ количество запросов *Q*, затем *Q* строк с описани€ми запросов.
√арантируетс€, что в каждом запросе **CHECK** и **ADD** слова ***word1*** и ***word2*** различны.
¬се слова состо€т лишь из латинских букв, цифр и символов подчЄркивани€.

##### ‘ормат вывода #####
ƒл€ каждого запроса в соответствующей строке выведите ответ на него:

* ¬ ответ на запрос **COUNT *word*** выведите единственное целое число Ч количество синонимов слова ***word***.
* ¬ ответ на запрос **CHECK *word1 word2*** выведите строку **YES**, если ***word1*** и ***word2*** €вл€ютс€ синонимами,
 и **NO** в противном случае.
 */


#include <string>
#include <set>
#include <map>
#include <iostream>
#include <sstream>
#include "w2-17.hpp"

void Test2w17(const std::string& input, const std::string& expected) {
	std::string log="";
	std::map<std::string, std::set<std::string>> db;
	std::istringstream iss(input);
	int command_count;
	iss >> command_count;
	for (int i = 0; i < command_count; i++) {
		std::string command;
		iss >> command;
		if (command == "ADD") {
			std::string word1, word2;
			iss >> word1 >> word2;
			db[word1].insert(word2);
			db[word2].insert(word1);
		}
		else if (command == "COUNT") {
			std::string word;
			iss >> word;
			log.append(std::to_string(db[word].size())+"\n");
		}
		else if (command == "CHECK") {
			std::string word1, word2;
			iss >> word1 >> word2;
			//auto temp = db[word1];
			if (std::find(db[word1].begin(), db[word1].end(), word2) != db[word1].end()) {
				log.append("YES\n");
			}
			else {
				log.append("NO\n");
			}

		}
		else { std::clog << "Unrecognized command: " << command; }
	}
	log.pop_back();
	std::clog << "'" << log << "'" << std::endl << "'" << expected << "'" << std::endl;
	if (log == expected) {
		std::clog << "Test passed :)" << std::endl;
	}
	else {
		std::clog << "Test failed :(, but i'm not sure :)" << std::endl;
	}


}
void RunTests2w17() {
	std::string input = R"(8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java)";
	std::string expected = R"(0
2
1
YES
NO
NO)";
	Test2w17(input, expected);
}