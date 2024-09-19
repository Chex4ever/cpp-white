#pragma once
#include <string>
#include <vector>
#include <sstream>

template <typename T>
std::string VectorToString(const std::vector<T>& v)
{
    std::ostringstream oss;
    for (size_t i = 0, size=v.size(); i < size; i++)
    {
        oss << v[i];
        if (i != size - 1)
        {
            oss << " ";
        }
    }
    return oss.str();
}