/*#### Задание по программированию: Разворот последовательности ####

Реализуйте функцию *void Reverse(vector<int>& v)*, которая переставляет элементы вектора в обратном порядке.

```objectivec
vector<int> numbers = {1, 5, 3, 4, 2};
Reverse(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
```
*/
#include "w2-6.hpp"
#include <string>
#include <vector>
#include <iostream>
#include "VectorToString.hpp"
template <typename T>
void Reverse(std::vector<T> &v)
{

    for (int i = 0; i < v.size() / 2; i++)
    {
        size_t reverse_i = v.size() - 1 - i;
        auto tmp = v[i];
        v[i] = v[reverse_i];
        v[reverse_i] = tmp;
    }
}

template <typename T>
void Test2w6(std::vector<T> v, const std::vector<T> &expected)
{
    std::clog << "Testing: " << VectorToString(v) << std::endl;
    Reverse(v);
    std::clog << "  Actual: " << VectorToString(v) << std::endl;
    std::clog << "  Expected: " << VectorToString(expected) << std::endl;
    std::clog << "  Test " << ((v == expected) ? "pass :)" : "fail :(") << std::endl;
}

void RunTests2w6()
{
    std::clog << "Testing 2w6: reverse" << std::endl;
    Test2w6(std::vector<std::string>{"a", "b", "c"}, {"c", "b", "a"});
    Test2w6(std::vector<std::string>{"a"}, {"a"});
    Test2w6(std::vector<int>{0, 1, 2, 3, 4, 5}, {5, 4, 3, 2, 1, 0});
    Test2w6(std::vector<int>{0, 1, 2, 3, 4, 5, 6}, {6, 5, 4, 3, 2, 1, 0});
}

// int main()
// {
//     RunTests2w6();
// }