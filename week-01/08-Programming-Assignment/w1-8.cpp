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

void Test(int a, int b, int expected)
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

void RunTests()
{
    Test(25, 27, 1);
    Test(12, 16, 4);
    Test(13, 13, 13);
}

int main()
{
    int a, b;
    while (true)
    {
        cout << endl
             << "GCD calculator. \"0 0\" for test" << endl;
        cin >> a >> b;
        if (a == 0 && b == 0)
            RunTests();
        else
            CalculateNod(a, b);
    }
    return 0;
}