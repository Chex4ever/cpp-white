/*
#### Задание по программированию: Структура LectureTitle ####
...

Допишите конструктор и структуры *Specialization*, *Course*, *Week* так, 
чтобы объект *LectureTitle* можно было создать с помощью кода
...

но нельзя было с помощью следующих фрагментов кода:
...
*/

#include <string>
#include <iostream>
#include "w4-1.hpp"

void RunTests4w1() {
	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	//Это не компилируемыпе конструкторы по заданию:

	//LectureTitle title2("C++", "White belt", "4th"); //no constructor

	//LectureTitle title3 = { "C++", "White belt", "4th" }; //no constructor

	//LectureTitle title4 = { {"C++"}, {"White belt"}, {"4th"} }; //no constructor

	/*LectureTitle title5(  //no constructor
		Course("White belt"),
		Specialization("C++"),
		Week("4th")
	);*/

	/*LectureTitle title6(  //no constructor
		Specialization("C++"),
		Week("4th"),
		Course("White belt")
	);*/
	std::clog << "  EASY!" << std::endl;
}