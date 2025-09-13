#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

class Date {
public:
	Date();
	Date(int);
	Date(int, int);
	Date(int, int, int);
	std::string ToString() const;
	bool Validate();
	std::string LastError() const;
	void ClearError();
	friend bool operator==(const Date& lh, const Date& rh);
	friend std::ostream& operator<<(std::ostream& os, const Date& r);
	friend std::istream& operator>>(std::istream& is, Date& r);
	friend bool operator<(const Date& lh, const Date& rh);
private:
	int year;
	int month;
	int day;
	std::string last_error;
};