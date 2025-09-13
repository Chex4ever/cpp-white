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
    size_t right = a.length()-1;
    for (size_t left = 0, length= a.length() / 2; left < length; left++)
    {
        if (tolower(a[left]) != tolower(a[right]))
        {
            return false;
        }
        right--;
    }
    return true;
}

void Test2w2(std::string a, bool expected)
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

void RunTests2w2()
{
    Test2w2("Madam", true);
    Test2w2("gentleman", false);
    Test2w2("av;..;va", true);

}