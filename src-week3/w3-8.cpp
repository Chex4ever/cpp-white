/*
#### Тренировочное задание по программированию: Способы инициализации ####

Определите тип *Incognizable*, для которого следующий код будет корректен:
```objectivec
int main() {
  Incognizable a;
  Incognizable b = {};
  Incognizable c = {0};
  Incognizable d = {0, 1};
  return 0;
}
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include "w3-8.hpp"

std::string Incognizable::ToString() const {
	std::string result;
	for (auto el : db) {
		result.append(std::to_string(el) + " ");
	}
	return result;
}

int Incognizable::Size() const {
	return db.size();
}
void RunTests3w8() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = { 0 };
	Incognizable d = { 0, 1 };

	std::clog << "a: size=" << a.Size() << ", ToString=" << a.ToString() << std::endl;
	std::clog << "b: size=" << b.Size() << ", ToString=" << b.ToString() << std::endl;
	std::clog << "c: size=" << c.Size() << ", ToString=" << c.ToString() << std::endl;
	std::clog << "d: size=" << d.Size() << ", ToString=" << d.ToString() << std::endl;
	std::clog << "  EASY!" << std::endl;
}