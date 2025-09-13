#pragma once

#include <string>
#include <vector>

class FunctionPart {
public:
	FunctionPart(char new_operation, double new_value);
	double Apply(double source_value) const;
	void Invert();
private:
	char operation;
	double value;
};

class Function {
public:
	void AddPart(char, double);
	double Apply(double) const;
	void Invert();
private:
	std::vector<FunctionPart> parts;
};

struct Image {
	double quality;
	double freshness;
	double rating;
};

struct Params {
	double a;
	double b;
	double c;
};

Function MakeWeightFunction(const Params& params,
	const Image& image);
double ComputeImageWeight(const Params& params, const Image& image);
double ComputeQualityByWeight(const Params& params,
	const Image& image,
	double weight);
void Test4w2(const std::string& expected);
void RunTests4w2();