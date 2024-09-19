/*
#### ������������� ������� �� ����������������: ��������� �������� ������� ####

�������� ������� *BuildMapValuesSet*, ����������� �� ���� ������� *map<int, string>* � ������������ ��������� �������� ����� �������:

```objectivec
set<string> BuildMapValuesSet(const map<int, string>& m) {
  // ...
}
```

##### ������ #####
###### ��� ######
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

###### ����� ######
```objectivec
even
odd
```

� ���� ������ �� �������� ��� ���� �������� ���� � ����������� ������� *BuildMapValuesSet*. **���� ���� �� ������ ��������� ������� main**. ���� � �� ����� ������� *main*, �� �������� ������ ����������.
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