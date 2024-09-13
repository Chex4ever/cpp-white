/*#### Задание по программированию: Отбор палиндромов ####

Напишите функцию, которая

* называется *PalindromFilter*
* возвращает *vector<string>*
* принимает *vector<string>* words и *int minLength* и возвращает все строки из вектора words, которые являются палиндромами и имеют длину не меньше *minLength*

Входной вектор содержит не более 100 строк, длина каждой строки не больше 100 символов.

##### Примеры #####

|              words             |            minLength           |            результат           |
|:------------------------------:|:------------------------------:|:------------------------------:|
| abacaba, aba                   | 5                              |  abacaba                       |
| abacaba, aba                   | 2                              |  abacaba, aba                  |
| weew, bro, code                | 4                              |  weew                          |*/

#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::clog;
using std::cout;
using std::endl;

template <typename T>
void PrintVector(const std::vector<T>& v){
    for (int i=0; i<v.size();i++)
    {
        cout << v[i];
        if (i!=v.size()-1) {
            cout << ", ";
        } else {
            cout << ". ";
        }
    }
}

bool IsPalindrom(std::string a)
{
    int right = a.length() - 1;
    for (int left = 0; left < a.length() / 2; left++)
    {
        if (tolower(a[left]) != tolower(a[right]))
        {
            return false;
        }
        right--;
    }
    return true;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int min_length)
{
    std::vector<std::string> result;
    for (const auto &word : words)
    {
        if (word.length() >= min_length && IsPalindrom(word))
        {
            result.push_back(word);
        }
    }
    return result;
}

void Test(std::vector<std::string> words, int min_length, std::vector<std::string> expected)
{
    cout << "Start test: ";
    PrintVector(words);
    std::vector<std::string> actual = PalindromFilter(words, min_length);
    cout << endl << "  Actual: ";
    PrintVector(actual);
    cout << endl << "  Expected: ";
    PrintVector(expected);
    cout << endl << "  Test " << ((actual == expected) ? "pass" : "fail") << ": " << endl;
}

void RunTests()
{
    Test({"abacaba", "aba"}, 5, {"abacaba"});
    Test({"abacaba", "aba"}, 2, {"abacaba", "aba"});
    Test({"weew", "bro", "code"}, 4, {"weew"});
}

int main()
{
    RunTests();
    return 0;
}