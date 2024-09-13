/*#### Тренировочное задание по программированию: Деление ####

Дано два натуральных числа A и B, не превышающих 1 000 000. Напишите программу, которая вычисляет целую часть частного от деления A на B.

Если B = 0, выведите "Impossible".

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 10 2                           | 5                              |
| 3 5                            | 0                              |
| 11 0                           | Impossible                     |*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int CalculateDivider(int a, int b)
{
    if (b == 0)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << a / b << endl;
    return a / b;
}

void Test(int a, int b, int expected)
{
    cout << a << " " << b << " ";
    int actual = CalculateDivider(a, b);
    if (actual == expected)
    {
        cout << "Test pass" << endl;
    }
    else
    {
        cout << "Test fail" << endl;
    }
}

void RunTests()
{
    Test(10, 2, 5);
    Test(3, 5, 0);
    Test(11, 0, 0);
    Test(1000000, 1000000, 1);
    Test(999999, 1000000, 0);
}

int main()
{
    int a, b;
    while (true)
    {
        cout << endl
             << "A / B = X. Type A, B. \"0 0\" for test" << endl;
        cin >> a >> b;
        if (a == 0 && b == 0)
            RunTests();
        else
            CalculateDivider(a, b);
    }
    return 0;
}