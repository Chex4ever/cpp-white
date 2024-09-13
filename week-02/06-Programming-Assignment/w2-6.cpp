/*#### Задание по программированию: Разворот последовательности ####

Реализуйте функцию *void Reverse(vector<int>& v)*, которая переставляет элементы вектора в обратном порядке.

```objectivec
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
```
*/

#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

template <typename T>
void PrintVector(const std::vector<T>& input){
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

void Reverse(std::vector<std::string>& source, std::vector<std::string>& destination)
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