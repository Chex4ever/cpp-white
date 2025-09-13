/*
#### “ренировочное задание по программированию: ќбратима€ функци€ ####

–еализуйте рассказанный на лекции класс **Function**, позвол€ющий создавать, вычисл€ть и инвертировать функцию, состо€щую из следующих элементарных операций:

* прибавить вещественное число *x*;
* вычесть вещественное число *x*.

ѕри этом необходимо объ€вить константными все методы, которые по сути такими €вл€ютс€.
*/

#include <string>
#include <vector>
#include <iostream>
#include "w4-2.hpp"

FunctionPart::FunctionPart(char new_operation, double new_value) {
	operation = new_operation;
	value = new_value;
}
double FunctionPart::Apply(double source_value) const {
	if (operation == '+') {
		return source_value + value;
	}
	else {
		return source_value - value;
	}
}
void FunctionPart::Invert() {
	if (operation == '+') {
		operation = '-';
	}
	else {
		operation = '+';
	}
}

void Function::AddPart(char operation, double value) {
	parts.push_back({ operation,value });
}
double Function::Apply(double value) const {
	for (const auto& part : parts) {
		value = part.Apply(value);
	}
	return value;
}
void Function::Invert() {
	for (auto& part : parts) {
		part.Invert();
	}
	std::reverse(parts.begin(), parts.end());
}

Function MakeWeightFunction(const Params& params,
	const Image& image) {
	Function function;
	function.AddPart('-', image.freshness * params.a + params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}

double ComputeImageWeight(const Params& params, const Image& image) {
	Function function = MakeWeightFunction(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight) {
	Function function = MakeWeightFunction(params, image);
	function.Invert();
	return function.Apply(weight);
}

void Test4w2(const std::string& expected) {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	std::cout << ComputeImageWeight(params, image) << std::endl;
	std::cout << ComputeQualityByWeight(params, image, 46) << std::endl;


	std::clog << std::endl << expected << std::endl << "  EASY!" << std::endl;
}

void RunTests4w2() {
	std::string expected = R"(36
20)";
	Test4w2(expected);
}