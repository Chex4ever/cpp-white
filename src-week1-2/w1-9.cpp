/*#### Тренировочное задание по программированию: Деление ####

На вход дано натуральное число _N_. Выведите его в двоичной системе счисления без ведущих нулей.

##### Пример #####

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 5                              | 101                            |
| 32                             | 100000                         |
| 1                              | 1                              |*/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;

std::string PrintBinary(int a)
{
    std::string result;
    do
    {
        result = std::to_string(a & 1) + result; // да, подсмотрел алгоритм, так как хотелось что-нибудь по изящнее чем через степени двойки:
        // Делаем побитовое И с единицей - получаем правый бит и записываем в начало строки...
    } while (a >>= 1); //, и "сдвигаемся"
    cout << result << endl;
    return result;
}

void Test1w9(int a, std::string expected)
{
    cout << a << " ";
    std::string actual = PrintBinary(a);
    if (actual == expected)
    {
        cout << " Test pass: " << actual << " is equal " << expected << endl;
    }
    else
    {
        cout << " Test fail: " << actual << " not equal " << expected << endl;
    }
}

void RunTests1w9()
{
    Test1w9(5, "101");
    Test1w9(32, "100000");
    Test1w9(1, "1");
}

//int main()
//{
//    int a;
//    while (true)
//    {
//        cout << endl
//             << "Binary printer. \"-1\" for test" << endl;
//        cin >> a;
//        if (a == -1)
//            RunTests();
//        else
//            PrintBinary(a);
//    }
//    return 0;
//}