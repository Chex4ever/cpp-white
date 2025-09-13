#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include "rational.hpp"
Rational::Rational(int n, int d) :numerator(n), denominator(d) {
	if (denominator == 0) {
		throw std::invalid_argument("Invalid argument");
	}
	if (numerator == 0) { denominator = 1; }
	Reduce();
}
int Rational::Numerator() const { return numerator; }
int Rational::Denominator() const { return denominator; }
std::string Rational::ToString() const {
	return (std::to_string(numerator) + "/" + std::to_string(denominator));
}

const Rational operator+(const Rational& a, const Rational& b) {
	return Rational(a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
}
const Rational operator-(const Rational& a, const Rational& b) {
	return Rational(a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
}
const Rational operator*(const Rational& a, const Rational& b) {
	return Rational(a.numerator * b.numerator, a.denominator * b.denominator);
}
const Rational operator/(const Rational& a, const Rational& b) {
	if (b.numerator == 0) {
		throw std::domain_error("Division by zero");
	}
	return Rational(a.numerator * b.denominator, a.denominator * b.numerator);
}
bool operator==(const Rational& lh, const Rational& rh) {
	return (lh.numerator == rh.numerator && lh.denominator == rh.denominator);
}
std::ostream& operator<<(std::ostream& os, const Rational& r) {
	os << r.numerator << "/" << r.denominator;
	return os;
}
std::istream& operator>>(std::istream& is, Rational& r) {
	if (is.rdbuf()->in_avail() == 0) {
		return is;
	}
	int a, b;
	char c;
	is >> a >> c >> b;
	if (is.fail()) {
		throw std::invalid_argument("Invalid argument");
	}
	if (c == '/') {
		r = Rational(a, b);
	}
	return is;
}
bool operator<(const Rational& lh, const Rational& rh) {
	return (lh.numerator * rh.denominator < rh.numerator * lh.denominator);
}
void Rational::Reduce() {
	if (numerator == 1 || denominator == 1 || numerator == 0 || denominator == 0) { return; }
	int nod = CalculateNod(numerator, denominator);
	numerator /= nod;
	denominator /= nod;
}
int Rational::CalculateNod(int a, int b)
{
	int result = a > b ? b : a;
	int remainder = a > b ? a % b : b % a;
	while (remainder != 0)
	{
		int temp = result;
		result = remainder;
		remainder = temp % remainder;
	}
	return result;
}
