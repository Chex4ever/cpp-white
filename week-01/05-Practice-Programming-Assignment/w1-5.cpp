/*#### Тренировочное задание по программированию: Расчёт стоимости товара ####

Написать программу вычисления стоимости покупки с учётом скидки.
Скидка в X процентов предоставляется, если сумма покупки больше _A_ рублей, в _Y_ процентов - если сумма больше _B_ рублей.

В стандартном вводе содержится пять вещественных чисел, разделённых пробелом:
_N, A, B, X, Y (A < B)_ - где _N_ - исходная стоимость товара. Выведите стоимость покупки с учётом скидки.

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 100 110 120 5 10               | 100                            |
| 115 110 120 5 10               | 109.25                         |
| 150 110 120 5 12.5             | 131.25                         |*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

double CalculatePrice(double price, double discount_small_limit, double discount_big_limit, float discount_small_percent, float discount_big_percent)
{
    double final_price = price;
    if (price > discount_big_limit)
    {
        final_price = price - price * (discount_big_percent / 100);
    }
    else if (price > discount_small_limit)
    {
        final_price = price - price * (discount_small_percent / 100);
    }
    cout << final_price << endl;
    return final_price;
}

void Test(double price, double discount_small_limit, double discount_big_limit, float discount_small_percent, float discount_big_percent, double expected)
{
    cout << price << " " << discount_small_limit << " " << discount_big_limit << " " << discount_small_percent << " " << discount_big_percent << " ";
    double actual = CalculatePrice(price, discount_small_limit, discount_big_limit, discount_small_percent, discount_big_percent);
    if (actual == expected)
    {
        cout << "Test pass: " << actual << " is equal " << expected << endl;
    }
    else
    {
        cout << "Test fail: " << actual << " not equal " << expected << endl;
    }
}

void RunTests()
{
    Test(100, 110, 120, 5, 10, 100);
    Test(115, 110, 120, 5, 10, 109.25);
    Test(150, 110, 120, 5, 12.5, 131.25);
}

int main()
{
    double price, discount_small_limit, discount_big_limit;
    float discount_small_percent, discount_big_percent;
    while (true)
    {
        cout << endl
             << "You know what to do. \"0 0 0 0 0\" for test" << endl;
        cin >> price >> discount_small_limit >> discount_big_limit >> discount_small_percent >> discount_big_percent;
        if (price == 0 && discount_small_limit == 0 && discount_big_limit == 0 && discount_small_percent == 0 && discount_big_percent == 0)
            RunTests();
        else
            CalculatePrice(price, discount_small_limit, discount_big_limit, discount_small_percent, discount_big_percent);
    }
    return 0;
}