/*
#### Задание по программированию: Ежемесячные дела ####

У каждого из нас есть ежемесячные дела, каждое из которых нужно выполнять в конкретный день каждого месяца: оплата счетов за электричество,
абонентская плата за связь и пр. Вам нужно реализовать работу со списком таких дел, а именно, обработку следующих операций:

**ADD *i s***
Добавить дело с названием ***s*** в день ***i***.

**NEXT**
Закончить текущий месяц и начать новый. Если новый месяц имеет больше дней, чем текущий, добавленные дни изначально не будут содержать дел.
Если же в новом месяце меньше дней, дела со всех удаляемых дней необходимо будет переместить на последний день нового месяца.
Обратите внимание, что количество команд этого типа может превышать 11.

**DUMP *i***
Вывести все дела в день ***i***.
Изначально текущим месяцем считается январь. Количества дней в месяцах соответствуют Григорианскому календарю с той лишь разницей, 
что в феврале всегда 28 дней.

##### Указание #####
Для дописывания всех элементов вектора *v2* в конец вектора *v1* удобно использовать метод *insert*:
v1.insert(end(v1), begin(v2), end(v2));

##### Формат ввода #####
Сначала число операций *Q*, затем описания операций.
Названия дел ***s*** уникальны и состоят только из латинских букв, цифр и символов подчёркивания. 
Номера дней ***i*** являются целыми числами и нумеруются от 1 до размера текущего месяца.

##### Формат вывода #####
Для каждой операции типа **DUMP** в отдельной строке выведите количество дел в соответствующий день, 
а затем их названия, разделяя их пробелом. Порядок вывода дел в рамках каждой операции значения не имеет.
*/

#include <iostream>
#include <string>
#include <vector>
#include "VectorToString.hpp"
#include "Todo.hpp"
#include "w2-10.hpp"



std::string TodoManipulator(int size,const std::vector<std::string>& v)
{
	Todo todo_list;
	std::string result = "";
	int i{ 0 }, counter{ 0 };
	while (counter < size) {
		std::string command = v[i++];
		if (command == "ADD")
		{
			int day = std::stoi(v[i++]);
			std::string name = v[i++];
			todo_list.Add(day,name);
		}
		else if (command == "DUMP") {
			int data = std::stoi(v[i++]);
			if (!result.empty()) { result += "\n"; }
			result += todo_list.Dump(data);
		}
		else if (command == "NEXT") {
			todo_list.Next();
		}
		else {
			std::clog << "command not recognized" << std::endl;
		}
		counter++;
	}
	return result;
}

void Test2w10(int size, std::vector<std::string> v, const std::string& expected)
{
	std::cout << "Testing: " << size << std::endl
		<< VectorToString(v) << std::endl;
	std::string actual = TodoManipulator(size, v);
	std::cout << "  Actual: " << std::endl << actual  << std::endl;
	std::cout << "  Expected: " << std::endl << expected  << std::endl;
	std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(, But this is not for sure :)") << std::endl;
}

void RunTests2w10()
{
	Test2w10(12, { "ADD", "5", "Salary", "ADD", "31", "Walk", 
		"ADD", "30", "WalkPreparations", "NEXT", "DUMP", "5", 
		"DUMP", "28", "NEXT", "DUMP" , "31" , "DUMP" , "30" , 
		"DUMP" , "28" , "ADD" , "28" , "Paymnet" , "DUMP" , "28" }, 
		"1 Salary\n2 WalkPreparations Walk\n0\n0\n2 WalkPreparations Walk\n3 WalkPreparations Walk Payment");
}