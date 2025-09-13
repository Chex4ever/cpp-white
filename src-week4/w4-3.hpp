#pragma once

#include <string>
#include <vector>
#include "w4-2.hpp"
class FunctionPart2 {
public:
	FunctionPart2(char, double);
	double Apply(double ) const;
	void Invert();
private:
	char operation;
	double value;
};

class Function2 {
public:
	void AddPart(char, double);
	double Apply(double) const;
	void Invert();
private:
	std::vector<FunctionPart2> parts;
};

Function2 MakeWeightFunction2(const Params& params,
	const Image& image);
double ComputeImageWeight2(const Params& params, const Image& image);
double ComputeQualityByWeight2(const Params& params,
	const Image& image,
	double weight);
void Test4w3(const std::string& expected);
void RunTests4w3();