/*
#### Тренировочное задание по программированию: Анаграммы ####

Слова называются *анаграммами* друг друга, если одно из них можно получить перестановкой букв в другом.
Например, слово «eat» можно получить перестановкой букв слова «tea», поэтому эти слова являются анаграммами друг друга.
Даны пары слов, проверьте для каждой из них, являются ли слова этой пары анаграммами друг друга.

##### Указание #####
Один из способов проверки того, являются ли слова анаграммами друг друга, заключается в следующем.
Для каждого слова с помощью словаря подсчитаем, сколько раз в нём встречается каждая буква.
Если для обоих слов эти словари равны (а это проверяется с помощью обычного оператора ==),
то слова являются анаграммами друг друга, в противном случае не являются.

При этом построение такого словаря по слову удобно вынести в отдельную функцию *BuildCharCounters*.

##### Формат ввода #####
Сначала дано число пар слов _N_, затем в _N_ строках содержатся пары слов, которые необходимо проверить.
Гарантируется, что все слова состоят лишь из строчных латинских букв.

##### Формат вывода #####
Выведите _N_ строк: для каждой введённой пары слов **YES**, если эти слова являются анаграммами, и **NO** в противном случае.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "VectorToString.hpp"
#include "w2-11.hpp"


std::map<char, int> BuildCharCounters(std::string input) {
	std::map<char, int> result;
	for(char ch : input)
	{
		result[ch]++;
	}
	return result;
}

std::string AnagramFinder(int size,const std::vector<std::string>& v)
{
	std::string result = "";
	int i{ 0 }, counter{ 0 };
	while (counter < size) {
		std::string word1 = v[i++];
		std::string word2 = v[i++];
		if (!result.empty()) { result += "\n"; }
		if (BuildCharCounters(word1) == BuildCharCounters(word2)) {
			result += "YES";
		}
		else {
			result += "NO";
		}
		counter++;
	}
	return result;
}

void Test2w11(int size, std::vector<std::string> v, const std::string& expected)
{
	std::cout << "Testing: " << size << std::endl
		<< VectorToString(v) << std::endl;
	std::string actual = AnagramFinder(size, v);
	std::cout << "  Actual: " << std::endl << actual  << std::endl;
	std::cout << "  Expected: " << std::endl << expected  << std::endl;
	std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << std::endl;
}

void RunTests2w11()
{
	Test2w11(3, { "eat", "tea", "find", "search", "master", "stream" }, "YES\nNO\nYES");
}