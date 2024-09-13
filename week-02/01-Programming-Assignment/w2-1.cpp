/*#### Задание по программированию: Факториал ####

Напишите функцию, которая

* называется *Factorial*
* возвращает *int*
* принимает *int* и возвращает факториал своего аргумента. Гарантируется, что аргумент функции по модулю не превышает 10.
Для отрицательных аргументов функция должна возвращать 1.

|        Аргумент функции        |            Результат           |
|:------------------------------:|:------------------------------:|
| 1                              | 1                              |
| -2                             | 1                              |
| 4                              | 24                             |

##### Пояснение #####
В этой задаче на проверку вам надо прислать файл с реализацией функции *Factorial*. **Этот файл не должен содержать функцию main**. Если в нём будет функция main, вы получите ошибку компиляции.*/

#include <iostream>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

int Factorial(int a)
{
    int result = 1;
    if (a > 0)
    {
        for (int i = 1; i < a; result *= ++i){}
    }
    else if (a == 0)
    {
        result = 0;
    }
    return result;
}

void Test(int a, int expected)
{
    cout << a << " ";
    int actual = Factorial(a);
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
    Test(1, 1);
    Test(-2, 1);
    Test(4, 24);
}

int main()
{
    int a;
    while (true)
    {
        cout << endl
             << "Factorial calculator. \"123\" for test" << endl;
        cin >> a;
        if (a == 123)
            RunTests();
        else
            cout << Factorial(a);
    }
    return 0;
}