/*#### Задание по программированию: Наибольший общий делитель ####

В *stdin* даны два натуральных числа. Найти их наибольший общий делитель.


|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 25 27                          | 1                              |
| 12 16                          | 4                              |
| 13 13                          | 13                             |*/

#include <iostream>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

int CalculateNod(int a, int b)
{
    int result = a > b ? b : a;
    int remainder = a > b ? a % b : b % a;
    while (remainder != 0)
    {
        int temp = result;
        result = remainder;
        remainder = temp % remainder;
    }
    cout << result << endl;
    return result;
}

void Test1w8(int a, int b, int expected)
{
    cout << a << " " << b << " ";
    int actual = CalculateNod(a, b);
    if (actual == expected)
    {
        cout << " Test pass: " << actual << " is equal " << expected << endl;
    }
    else
    {
        cout << " Test fail: " << actual << " not equal " << expected << endl;
    }
}

void RunTests1w8()
{
    Test1w8(25, 27, 1);
    Test1w8(12, 16, 4);
    Test1w8(13, 13, 13);
}