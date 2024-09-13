/*#### Тренировочное задание по программированию: Палиндром ####

Напишите функцию, которая

* называется *IsPalindrom*
* возвращает *bool*
* принимает параметр типа string и возвращает, является ли переданная строка палиндромом

Палиндром - это слово или фраза, которые одинаково читаются слева направо и справа налево.

|        Аргумент функции        |            Результат           |
|:------------------------------:|:------------------------------:|
| madam                          | true                           |
| gentleman                      | false                          |*/

#include <iostream>
#include <string>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

bool IsPalindrom(std::string a)
{
    int right = a.length()-1;
    for (int left = 0; left < a.length()/2; left++)
    {
        if (tolower(a[left]) != tolower(a[right]))
        {
            return false;
        }
        right--;
    }
    return true;
}

void Test(std::string a, bool expected)
{
    cout << a << " ";
    bool actual = IsPalindrom(a);
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
    Test("Madam", true);
    Test("gentleman", false);
    Test("av;..;va", true);

}

int main()
{
    std::string a;
    while (true)
    {
        cout << endl
             << "Palindrom detector :). \"t\" for test" << endl;
        cin >> a;
        if (a == "t")
            RunTests();
        else
            cout << IsPalindrom(a);
    }
    return 0;
}