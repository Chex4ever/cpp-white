/*#### Тренировочное задание по программированию: Максимизатор ####

Напишите функцию *UpdateIfGreater*, которая принимает два целочисленных аргумента: *first* и *second*.
Если *first* оказался больше *second*,Ваша функция должна записывать в *second* значение параметра *first*.
При этом изменение параметра *second* должно быть видно на вызывающей стороне.*/

#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

template <typename T>
void UpdateIfGreater(const T &first, T &second)
{
    if (first > second)
    {
        second = first;
    }
}

template <typename T>
void Test2w4(T first, T second, T expected)
{
    cout << "Testing: " << first << " vs " << second << endl;
    UpdateIfGreater(first, second);
    cout << "  Actual: " << second << endl;
    cout << "  Expected: " << expected << endl;
    cout << "  Test " << ((second == expected) ? "pass" : "fail") << endl;
}

void RunTests2w4()
{
    Test2w4(1, 2, 2);
    Test2w4(3, 2, 3);
    Test2w4(0, 0, 0);
    Test2w4(100500, 100500, 100500);
    Test2w4(-1, 123, 123);
    Test2w4("a", "b", "b"); // пока ничего не понятно, но очень интересно - если ставлю expected "b" - функция возвращает "a"; а если expected "a" - то функция ворвращает "b" - какая-то квантовая магия :)
}
//int main()
//{
//    RunTests();
//    return 0;
//}