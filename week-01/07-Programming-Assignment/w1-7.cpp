/*#### Задание по программированию: Второе вхождение ####

Дана строка. Найдите в этой строке второе вхождение буквы **f** и выведите индекс этого вхождения. Если буква **f** в данной строке встречается только один раз, выведите число -1, а если не встречается ни разу, выведите число -2. Индексы нумеруются с нуля.

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| comfort                        | -1                             |
| coffee                         | 3                              |
| car                            | -2                             |*/

#include <iostream>
#include <string>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::string;

int FindSecondF(const string& input)
{
    int result = -2;
    int count = 0;
    for (int i=0; i < input.length(); i++)
    {
        if (input[i] == 'f')
        {
            clog << "fpos1=" << i << "; ";
            count++;
            result = -1;
            if (count == 2)
            {
                clog << "fpos2=" << i << "; ";
                result = i;
                break;
            }
        }
    }
    cout << result << endl;
    return result;
}

void Test(string input, int expected)
{
    cout << input << " ";
    int actual = FindSecondF(input);
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
    Test("comfort", -1);
    Test("coffee", 3);
    Test("car", -2);
}

int main()
{
    string input;
    while (true)
    {
        cout << endl
             << "Type word for second f position. \"0\" for test" << endl;
        cin >> input;
        if (input == "0")
            RunTests();
        else
            FindSecondF(input);
    }
    return 0;
}