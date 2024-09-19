#pragma once

#include <string>

struct Specialization {
	std::string value;
	explicit Specialization(std::string new_value) {
		value = new_value;
	}
};
struct Course {
	std::string value;
	explicit Course(std::string new_value) {
		value = new_value;
	}
};
struct Week {
	std::string value;
	explicit Week(std::string new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	LectureTitle(Specialization s, Course c, Week w) {
		specialization = s.value;
		course = c.value;
		week = w.value;
	}
	std::string specialization;
	std::string course;
	std::string week;
};

void RunTests4w1();