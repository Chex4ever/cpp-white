#include <chrono>
#include <format>
#include <string>
#include <sstream>
#include "date.hpp"

Date::Date() {
	const auto now = std::chrono::system_clock::now();
	year = std::stoi(std::format("{:%Y}", now));
	month = std::stoi(std::format("{:%m}", now));
	day = std::stoi(std::format("{:%d}", now));
}
Date::Date(int d) : day(d) {
	const auto now = std::chrono::system_clock::now();
	year = std::stoi(std::format("{:%Y}", now));
	month = std::stoi(std::format("{:%m}", now));
	Validate();
}
Date::Date(int m, int d) : day(d), month(m) {
	const auto now = std::chrono::system_clock::now();
	year = std::stoi(std::format("{:%Y}", now));
	Validate();
}
Date::Date(int y, int m, int d) : year(y), month(m), day(d) {
	Validate();
}

std::string Date::ToString() const {
	std::string tmp;
	tmp = std::format("{:04d}-{:02d}-{:02d}", year, month, day);
	return tmp;
}

bool Date::Validate() {
	if (month < 1 || month>12) {
		last_error = "Month value is invalid: " + std::to_string(month);
		return false;
	}
	if (day < 1 || day>31) {
		last_error = "Day value is invalid: " + std::to_string(day);
		return false;
	}
	return true;
}
std::string Date::LastError() const {
	return last_error;
}

void Date::ClearError() {
	last_error.clear();
}
bool operator==(const Date& lh, const Date& rh) {
	return lh.year == rh.year || lh.month == rh.month || lh.day == rh.day;
}
std::ostream& operator<<(std::ostream& os, const Date& date) {
	os << date.ToString();
	return os;
}

std::istream& operator>>(std::istream& is, Date& date) {
	if (is.rdbuf()->in_avail() == 0) {
		return is;
	}
	int y, m, d;
	char a, b;

	is >> y >> a >> m >> b >> d;
	if (is.fail() || a != b) {
		throw std::invalid_argument("Invalid argument");
	}
	if (a == '-') {
		date = Date(y, m, d);
	}
	return is;
}
bool operator<(const Date& lh, const Date& rh) {
	//return lh.year < rh.year || lh.month < rh.month || lh.day < rh.day;
	return lh.ToString()<rh.ToString();
}