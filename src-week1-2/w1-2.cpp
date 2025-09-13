/* #### Задание по программированию: Минимальная строка ####
 *
 *В стандартном потоке даны три строки, разделённые пробелом. Каждая строка состоит из строчных латинских букв и
 *имеет длину не более 30 символов. Выведите в стандартный вывод лексикографически минимальную из них.
 *
 *|             stdin              |             stdout             |
 *|:------------------------------:|:------------------------------:|
 *| milk milkshake month           | milk                           |
 *| c a b                          | a                              |
 *| fire fog wood                  | fire                           |
 */

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

string FindMinimalString(string a, string b, string c)
{
    return (a <= b) ? (a <= c) ? a 
                               : (b <= c) ? b
                                          : c
                    : c;
}

void Test1w2(string a, string b, string c, string expected)
{
    cout << a << " " << b << " " << c << " ";
    string actual = FindMinimalString(a, b, c);
    if (actual == expected)
    {
        cout << "pass" << endl;
    }
    else
    {
        cout << actual << endl;
    }
}

void RunTests1w2()
{
    Test1w2("milk", "milkshake", "month", "milk");
    Test1w2("c", "a", "b", "a");
    Test1w2("fire", "fog", "wood", "fire");
    Test1w2("a", "a", "a", "a");
    Test1w2("b", "a", "a", "a");
    Test1w2("a", "b", "a", "a");
    Test1w2("a", "a", "b", "a");
}

//int main()
//{
//    string a, b, c;
//    while (true)
//    {
//        cout << "Type three words. \"0 0 0\" for test" << endl;
//        cin >> a >> b >> c;
//        if (a == "0" && b == "0" && c == "0")
//            RunTests1w2();
//        else
//            cout << FindMinimalString(a, b, c) << endl;
//    }
//    return 0;
//}