/*
#### Задание по программированию: Очередь ####
Люди стоят в очереди, но никогда не уходят из её начала, зато могут приходить в конец и уходить оттуда. Более того, иногда
некоторые люди могут прекращать и начинать беспокоиться из-за того, что очередь не продвигается.
Реализуйте обработку следующих операций над очередью:
* **WORRY *i***: пометить ***i***-го человека с начала очереди (в нумерации с 0) как беспокоящегося;
* **QUIET *i***: пометить ***i***-го человека как успокоившегося;
* **COME *k***: добавить ***k*** спокойных человек в конец очереди;
* **COME *-k***: убрать ***k*** человек из конца очереди;
* **WORRY_COUNT**: узнать количество беспокоящихся людей в очереди.
Изначально очередь пуста.
##### Формат ввода #####
Количество операций *Q*, затем описания операций.
Для каждой операции **WORRY *i*** и **QUIET *i*** гарантируется, что человек с номером ***i*** существует в очереди на момент операции.
Для каждой операции **COME *-k*** гарантируется, что ***k*** не больше текущего размера очереди.
##### Формат вывода #####
Для каждой операции **WORRY_COUNT** выведите одно целое число — количество беспокоящихся людей в очереди.
##### Пример #####
###### Ввод ######
8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT
###### Вывод ######
1
2
*/

#include <iostream>
#include <string>
#include <vector>
#include "VectorToString.hpp"
#include "PeopleQueue.hpp"
#include "w2-9.hpp"

std::string PeopleQueueManipulator(int size,const std::vector<std::string>& v)
{
	PeopleQueue queue;
	std::string result = "";
	int i{ 0 }, counter{ 0 };
	while (counter < size) {
		std::string command = v[i++];
		if (command == "COME")
		{
			int data = std::stoi(v[i++]);
			queue.Come(data);
		}
		else if (command == "WORRY") {
			int data = std::stoi(v[i++]);
			queue.Worry(data);
		}
		else if (command == "WORRY_COUNT") {
			if (!result.empty()) { result += "\n"; }
			result += std::to_string(queue.WorryCount());
		}
		else if (command == "QUIET") {
			int data = std::stoi(v[i++]);
			queue.Quiet(data);
		}
		else {
		}
		counter++;
	}
	return result;
}

void Test2w9(int size, std::vector<std::string> v, const std::string& expected)
{
	std::cout << "Testing: " << size << std::endl
		<< VectorToString(v) << std::endl;
	std::string actual = PeopleQueueManipulator(size, v);
	std::cout << "  Actual: " << std::endl << actual  << std::endl;
	std::cout << "  Expected: " << std::endl << expected  << std::endl;
	std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << std::endl;
}

void RunTests2w9()
{
	Test2w9(8, { "COME", "5", "WORRY", "1", "WORRY", "4", 
		"COME", "-2", "WORRY_COUNT", "COME", "3", "WORRY", 
		"3", "WORRY_COUNT" }, "1\n2");
}
