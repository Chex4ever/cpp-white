#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "rational.hpp"
class Rational {
public:
	Rational(int n = 0, int d = 1);
	int Numerator() const;
	int Denominator() const;
	std::string ToString() const;
	friend const Rational operator+(const Rational& a, const Rational& b);
	friend const Rational operator-(const Rational& a, const Rational& b);
	friend const Rational operator*(const Rational& a, const Rational& b);
	friend const Rational operator/(const Rational& a, const Rational& b);
	friend bool operator==(const Rational& lh, const Rational& rh);
	friend std::ostream& operator<<(std::ostream& os, const Rational& r);
	friend std::istream& operator>>(std::istream& is, Rational& r);
	friend bool operator<(const Rational& lh, const Rational& rh);
private:
	int numerator;
	int denominator;
	void Reduce();
	int CalculateNod(int a, int b);
};