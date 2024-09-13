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

void Test(string a, string b, string c, string expected)
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

void RunTests()
{
    Test("milk", "milkshake", "month", "milk");
    Test("c", "a", "b", "a");
    Test("fire", "fog", "wood", "fire");
    Test("a", "a", "a", "a");
    Test("b", "a", "a", "a");
    Test("a", "b", "a", "a");
    Test("a", "a", "b", "a");
}

int main()
{
    string a, b, c;
    while (true)
    {
        cout << "Type three words. \"0 0 0\" for test" << endl;
        cin >> a >> b >> c;
        if (a == "0" && b == "0" && c == "0")
            RunTests();
        else
            cout << FindMinimalString(a, b, c) << endl;
    }
    return 0;
}