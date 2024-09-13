/*#### Задание по программированию: Перемещение строк ####

Напишите функцию *MoveStrings*, которая принимает два вектора строк, *source* и *destination*, 
и дописывает все строки из первого вектора в конец второго. После выполнения функции вектор *source* должен оказаться пустым.

*Чтобы очистить содержимое вектора, надо вызвать у него метод clear*:

```objectivec
vector<string> words = {"hey", "hi"};
words.clear();
```

##### Пример #####
```objectivec
vector<string> source = {"a", "b", "c"};
vector<string> destination = {"z"};
MoveStrings(source, destination);
// source должен оказаться пустым
// destination должен содержать строки "z", "a", "b", "c" именно в таком порядке*/

#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

// template <typename T>
void PrintVector(const std::vector<std::string>& v){
    std::string result = "";
    cout << "{";
    for (int i=0; i<v.size();i++)
    {
        cout << v[i];
        if (i!=v.size()-1) {
            cout << ", ";
        } else {
            cout << "} ";
        }
    }
}

void MoveStrings(std::vector<std::string>& source, std::vector<std::string>& destination)
{
    destination.insert(destination.end(), source.begin(), source.end());
    source.clear();
}

void Test(std::vector<std::string> source, std::vector<std::string> destination, const std::vector<std::string>& expected)
{
    cout << "Testing: ";
    PrintVector(source);
    cout << " vs ";
    PrintVector(destination);
    cout << endl;
    MoveStrings(source, destination);
    cout << "  Actual: ";
    PrintVector(destination);
    cout << endl;
    cout << "  Expected: ";
    PrintVector(expected);
    cout << endl;
    cout << "  Sourse vector is " << (source.empty()?"empty.":"not empty.") << endl;
    cout << "  Test " << ((destination == expected && source.empty()) ? "pass :)" : "fail :(") << endl;
}

void RunTests()
{
    Test({"a", "b" , "c"}, {"z"}, {"z", "a", "b" , "c"});
    Test({"a"}, {"b"}, {"b", "a"});
    Test({"d", "e" , "f"}, {"a", "b" , "c"}, {"a", "b" , "c", "d", "e" , "f"});
}

int main()
{
    RunTests();
    return 0;
}