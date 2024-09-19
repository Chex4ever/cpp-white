/*#### Тренировочное задание по программированию: Чётные числа ####

Дано два целых числа *A* и *B* *(A <= B, A >= 1, B <= 30000)*. Выведите через пробел все чётные числа от *A* до *B* (включительно).

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 1 10                           | 2 4 6 8 10                     |
| 2 3                            | 2                              |
| 9 11                           | 10                             |*/

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;


string PrintEvenNumbers(int start, int end)
{
    string result = "";//для задания, конечно, эта лишняя переменная не нужна, но для тестирования...
    if (start % 2 != 0)
        start++;
    if (end % 2 != 0)
        end--;
    for (start; start<=end;start+=2){
        result += std::to_string(start);
        if (start!=end) result+=" ";
    }
    cout << result;
    return result;
}

void Test1w6(int start, int end, string expected)
{
    cout << start << " " << end << " ";
    string actual = PrintEvenNumbers(start, end);
    if (actual == expected)
    {
        cout << " Test pass: " << actual << " is equal " << expected << endl;
    }
    else
    {
        cout << " Test fail: " << actual << " not equal " << expected << endl;
    }
}

void RunTests1w6()
{
    Test1w6(1, 10, "2 4 6 8 10");
    Test1w6(2, 3, "2");
    Test1w6(9, 11, "10");
}

//int main()
//{
//    int start, end;
//    while (true)
//    {
//        cout << endl
//             << "You know what to do. \"0 0\" for test" << endl;
//        cin >> start >> end;
//        if (start == 0 && end == 0)
//            RunTests();
//        else
//            PrintEvenNumbers(start, end);
//    }
//    return 0;
//}