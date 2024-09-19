/*
#### Тренировочное задание по программированию: Калькулятор обыкновенных дробей ####

Итак, теперь у нас с вами есть полноценный тип для представления обыкновенных дробей:
класс *Rational* интегрирован в язык с помощью перегрузки операторов и не позволяет выполнять
некорректные операции за счёт выбрасывания исключений. Давайте на основе класса *Rational*
создадим простой калькулятор для обыкновенных дробей.

Вам надо написать программу, которая считывает из стандартного ввода одну строку в формате
***ДРОБЬ_1 операция ДРОБЬ_2***. *ДРОБЬ_1* и *ДРОБЬ_2* имеют формат *X/Y*, где *X* — целое,
а *Y* — целое неотрицательное число. операция — это один из символов *'+', '-', '*', '/'*.

Если *ДРОБЬ_1* или *ДРОБЬ_2* является некорректной обыкновенной дробью, ваша программа должна
вывести в стандартный вывод сообщение *"Invalid argument"*. Если считанная операция — это
деление на ноль, выведите в стандартный вывод сообщение *"Division by zero"*. В противном
случае выведите результат операции.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "w4-11.hpp"
#include "rational.hpp"

bool ParseTest4w11(const std::string& input, const std::string& expected) {
	std::string log;
	std::istringstream iss_line(input);
	std::string line;
	while (std::getline(iss_line, line)) {
		std::istringstream iss(line);
		Rational lh, rh;
		char operation;
		try {
			iss >> lh >> operation >> rh;
			Rational result;
			switch (operation)
			{
			case '+':
				result = (lh + rh);
				break;
			case '-':
				result = (lh - rh);
				break;
			case '*':
				result = (lh * rh);
				break;
			case '/':
				result = (lh / rh);
				break;
			default:
				break;
			}
			log.append(result.ToString() + "\n");
		}
		catch (const std::invalid_argument& e) {
			log.append(e.what());
			log.append("\n");
		}
		catch (const std::domain_error& e) {
			log.append(e.what());
			log.append("\n");
		}
	}
	std::cout << log;
	log.pop_back();
	if (log == expected)
	{
		return true;
	}
	return false;
}

void RunTests4w11() {
	std::string input = R"(1/2 + 1/3
1/2 + 5/0
4/5 / 0/8)";
	std::string expected = R"(5/6
Invalid argument
Division by zero)";
	if (ParseTest4w11(input, expected)) {
		std::cout << "  Test passed! " << std::endl;
	}
	else {
		std::cout << "  Test fail!" << std::endl;
	}
}