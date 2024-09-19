/*
#### Тренировочное задание по программированию: Разворот последовательности — 2 ####

Реализуйте функцию *vector<int> Reversed(const vector<int>& v)*, возвращающую копию вектора v, в которой числа переставлены в обратном порядке.

|           Вектор v             |        Результат функции       |
|:------------------------------:|:------------------------------:|
| 1, 5, 3, 4, 2                  | 2, 4, 3, 5, 1                  |


*/

#include <iostream>
#include <algorithm>
#include <vector>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

template <typename T>
void PrintVector2w6(const std::vector<T> &v)
{
    std::string result = "";
    cout << "{";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i != v.size() - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << "} ";
        }
    }
}
template <typename T>
std::vector<T> Reversed(std::vector<T> v)
{

    for (int i = 0; i < v.size() / 2; i++)
    {
        size_t reverse_i = v.size() - 1 - i;
        clog << reverse_i;
        auto tmp = v[i];
        v[i] = v[reverse_i];
        v[reverse_i] = tmp;
    }
    return v;
}
template <typename T>
void Test2w7(std::vector<T> v, const std::vector<T> &expected)
{
    cout << "Testing: ";
    PrintVector2w6(v);
    cout << endl;
    std::vector<T> actual = Reversed(v);
    cout << "  Actual: ";
    PrintVector2w6(actual);
    cout << endl;
    cout << "  Expected: ";
    PrintVector2w6(expected);
    cout << endl;
    cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << endl;
}

void RunTests2w7()
{
    Test2w7(std::vector<std::string>{"a", "b", "c"}, {"c", "b", "a"});
    Test2w7(std::vector<std::string>{"a"}, {"a"});
    Test2w7(std::vector<int>{0, 1, 2, 3, 4, 5}, {5, 4, 3, 2, 1, 0});
    Test2w7(std::vector<int>{0, 1, 2, 3, 4, 5, 6}, {6, 5, 4, 3, 2, 1, 0});
}