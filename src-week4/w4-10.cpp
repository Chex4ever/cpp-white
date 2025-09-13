/*
#### «адание по программированию: »сключени€ в классе Rational ####

¬спомним класс *Rational*, который мы реализовали в задачах, посв€щЄнных перегрузке операторов.
“ам специально говорилось, что в тестах объекты класса *Rational* никогда не создаютс€ с
нулевым знаменателем и никогда не выполн€етс€ деление на ноль. Ќастало врем€ избавитьс€
от этого ограничени€ и научитьс€ обрабатывать нулевой знаменатель и деление на ноль.
¬ этой задаче вам предстоит это сделать.

ѕомен€йте реализацию конструктора класса *Rational* так, чтобы он выбрасывал исключение
*invalid_argument*, если знаменатель равен нулю.  роме того, переделайте реализацию оператора
делени€ дл€ класса *Rational* так, чтобы он выбрасывал исключение *domain_error*,
если делитель равен нулю.
*/

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "w4-10.hpp"
#include "rational.hpp"


void RunTests4w10() {


	std::cout << " Test 1: rational (1,0)" << std::endl;
	try{
		Rational test1(1, 0);
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << " Test 2: Rational (1,1) / 0" << std::endl;
	try{
		Rational test2(1, 1);
		Rational subzero = test2 / 0;
	}
	catch (std::domain_error& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "  Easy! ";
}