/*На вход вашей программе в стандартном вводе даны действительные коэффициенты _A_, _B_ и C уравнения
_Ax² + Bx + C = 0_. Выведите все его различные действительные корни в любом порядке.
Гарантируется, что хотя бы один из коэффициентов не равен нулю.

|             stdin              |             stdout             |
|:------------------------------:|:------------------------------:|
| 2 5 2                          | -0.5 -2                        |
| 2 4 2                          | -1                             |
| 2 1 2                          |                                |
| 0 4 10                         | -2.5                           |*/

#include <iostream>
#include <cmath>
#include <vector>

using std::cin;
using std::clog;
using std::cout;
using std::endl;
using std::vector;

vector<double> FindQuadraticRoots(double a, double b, double c)
{
    if ((b == 0 && c == 0) || (a == 0 && c == 0))
    {
        cout << 0 << endl;
        return {0};
    }
    if (a == 0)
    {
        clog << " This is not a quadratic equation. Answer is: ";
        double root = b != 0 ? -c / b : -c;
        cout << root << endl;
        return {root};
    }

    double d = b * b - 4 * a * c; // d is for discriminant
    clog << "d=" << d;
    if (d > 0)
    {
        clog << " Discriminant is positive. There are 2 roots: ";
        double root1 = (-1 * b + sqrt(d)) / (a * 2);
        double root2 = (-1 * b - sqrt(d)) / (a * 2);
        cout << root1 << " " << root2 << endl;
        return {root1, root2};
    }
    else if (d == 0)
    {
        clog << " Discriminant is zero. There is exactly one root: ";
        double root = -1 * b / (a * 2);
        cout << root << endl;
        return {root};
    }
    else
    {
        clog << " Discriminant is negative. There are no real roots. ";
        cout << endl;
        return {};
    }
}

void Test1w3(double a, double b, double c, vector<double> expected)
{
    cout << a << " " << b << " " << c << " ";
    vector<double> actual = FindQuadraticRoots(a, b, c);
    if (actual == expected)
    {
        cout << "Test pass" << endl;
    }
    else
    {
        cout << "Test fail" << endl;
    }
}

void RunTests1w3()
{
    Test1w3(2, 5, 2, {-0.5, -2});
    Test1w3(2, 4, 2, {-1});
    Test1w3(2, 1, 2, {});
    Test1w3(0, 4, 10, {-2.5});
    Test1w3(5, 0, -45, {3, -3});
    Test1w3(0.5, 0.125, 0, {0, -0.25});
    Test1w3(0, 0, 10, {-10});
    Test1w3(0, 10, 0, {0});
    Test1w3(10, 0, 0, {0});
}

//int main()
//{
//    double a, b, c;
//    while (true)
//    {
//        cout << endl
//             << "Ax2 + Bx + C = 0. Type a b c. \"0 0 0\" for test" << endl;
//        cin >> a >> b >> c;
//        if (a == 0 && b == 0 && c == 0)
//            RunTests();
//        else
//            FindQuadraticRoots(a, b, c);
//    }
//    return 0;
//}