/*
#### Тренировочное задание по программированию: Множество значений словаря ####

Напишите функцию *BuildMapValuesSet*, принимающую на вход словарь *map<int, string>* и возвращающую множество значений этого словаря:

```objectivec
set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}
```

##### Пример #####
###### Код ######
set<string> values = BuildMapValuesSet({
	{1, "odd"},
	{2, "even"},
	{3, "odd"},
	{4, "even"},
	{5, "odd"}
});

for (const string& value : values) {
  cout << value << endl;
}

###### Вывод ######
```objectivec
even
odd
```

В этой задаче на проверку вам надо прислать файл с реализацией функции *BuildMapValuesSet*. **Этот файл не должен содержать функцию main**. Если в нём будет функция *main*, вы получите ошибку компиляции.
*/


#include <string>
#include <set>
#include <map>
#include <iostream>
#include "w2-16.hpp"


std::set<std::string> BuildMapValuesSet(const std::map<int, std::string>& m) {
	std::set<std::string> result;
	for (const auto& record : m) {
		result.insert(record.second);
	}
	return result;
}

void RunTests2w16() {
	std::set<std::string> values = BuildMapValuesSet({
	{1, "odd"},
	{2, "even"},
	{3, "odd"},
	{4, "even"},
	{5, "odd"}
		});

	for (const std::string& value : values) {
		std::cout << value << std::endl;
	}
	std::clog << "  EASY!" << std::endl;
}