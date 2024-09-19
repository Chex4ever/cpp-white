/*
#### Задание по программированию: Обратимая функция с умножением и делением ####

Добавьте в класс *Function* из задачи «Обратимая функция» обработку умножения (__'*'__) и деления (__'/'__). Гарантируется отсутствие элементарных операций умножения и деления на 0.

*/

#include <string>
#include <vector>
#include <iostream>
#include "w4-3.hpp"

FunctionPart2::FunctionPart2(char new_operation, double new_value) {
	operation = new_operation;
	value = new_value;
}
double FunctionPart2::Apply(double source_value) const {
	switch (operation)
	{
	case '+':
		return source_value + value;
	case '-':
		return source_value - value;
	case '*':
		return source_value * value;
	case '/':
		if (value == 0) {
			return 0;
		}
		return source_value / value;
	default:
		break;
	}
}
void FunctionPart2::Invert() {
	switch (operation)
	{
	case '+':
		operation = '-';
		break;
	case '-':
		operation = '+';
		break;
	case '*':
		operation = '/';
		break;
	case '/':
		operation = '*';
		break;
	default:
		break;
	}
}

void Function2::AddPart(char operation, double value) {
	parts.push_back({ operation,value });
}
double Function2::Apply(double value) const {
	for (const auto& part : parts) {
		value = part.Apply(value);
	}
	return value;
}
void Function2::Invert() {
	for (auto& part : parts) {
		part.Invert();
	}
	std::reverse(parts.begin(), parts.end());
}

Function2 MakeWeightFunction2(const Params& params, const Image& image) {
	Function2 function;
	function.AddPart('*', params.a);
	function.AddPart('-', image.freshness * params.b);
	function.AddPart('+', image.rating * params.c);
	return function;
}
double ComputeImageWeight2(const Params& params, const Image& image) {
	Function2 function = MakeWeightFunction2(params, image);
	return function.Apply(image.quality);
}

double ComputeQualityByWeight2(const Params& params,
	const Image& image,
	double weight) {
	Function2 function = MakeWeightFunction2(params, image);
	function.Invert();
	return function.Apply(weight);
}
void Test4w3(const std::string& expected) {
	Image image = { 10, 2, 6 };
	Params params = { 4, 2, 6 };
	std::cout << ComputeImageWeight2(params, image) << std::endl;
	std::cout << ComputeQualityByWeight2(params, image, 52) << std::endl;


	std::clog << std::endl << expected << std::endl << "  EASY!" << std::endl;
}

void RunTests4w3() {
	std::string expected = R"(72
5)";
	Test4w3(expected);
}