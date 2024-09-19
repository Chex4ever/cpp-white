#pragma once
#include <string>
#include <vector>

bool IsPalindrom2(std::string a);
std::vector<std::string> PalindromFilter(std::vector<std::string> words, int min_length);
void Test2w3(std::vector<std::string> words, int min_length, std::vector<std::string> expected);
void RunTests2w3();