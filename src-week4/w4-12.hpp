#pragma once

#include <string>

std::string AskTimeServer(int test = 0);
class TimeServer;
bool ParseTest4w12(const std::string& input, const std::string& expected);
void RunTests4w12();