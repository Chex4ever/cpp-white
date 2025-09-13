/*
#### Тренировочное задание по программированию: Средняя температура ####
Даны значения температуры, наблюдавшиеся в течение N подряд идущих дней. Найдите номера дней (в нумерации с нуля) со значением температуры
выше среднего арифметического за все N дней.
Гарантируется, что среднее арифметическое значений температуры является целым числом.
##### Формат ввода #####
Вводится число N, затем N неотрицательных целых чисел — значения температуры в 0-й, 1-й, ... (N−1)-й день.
##### Формат вывода #####
Первое число K — количество дней, значение температуры в которых выше среднего арифметического. Затем K целых чисел — номера этих дней.
##### Пример #####
###### Ввод ######
5
7 6 3 0 9
###### Вывод ######
3
0 1 4
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "VectorToString.hpp"

int VectorSum(const std::vector<int> &v)
{
    int result = 0;
    for (size_t i = 0,size=v.size(); i < size; result += v[i++])
        ;
    return result;
}

std::vector<int> SelectElementsWithValueMoreThanAverage(int size, const std::vector<int> &v)
{
    int average = VectorSum(v) / (int)v.size();
    std::vector<int> result;
    for (size_t i=0,length=v.size(); i< length;i++)
    {
        if (v[i] > average) result.push_back(i);
    }
    return result;
}

std::string AverageTemperatue(int &size, const std::vector<int> &v)
{
    std::vector<int> tmp = SelectElementsWithValueMoreThanAverage(size, v);
    std::string result = std::to_string(tmp.size());

    result += "\n";
    result += VectorToString(tmp);
    return result;
}

void Test2w8(int size, std::vector<int> v, const std::string &expected)
{
    std::cout << "Testing: " << size << std::endl
         << VectorToString(v) << std::endl;
    std::string actual = AverageTemperatue(size, v);
    std::cout << "  Actual: " << actual << std::endl;
    std::cout << "  Expected: " << expected << std::endl;
    std::cout << "  Test " << ((actual == expected) ? "pass :)" : "fail :(") << std::endl;
}

void RunTests2w8()
{
    Test2w8(5, {7, 6, 3, 0, 9}, "3\n0 1 4");
}