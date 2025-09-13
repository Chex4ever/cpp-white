#pragma once
#include <map>
#include <set>
#include <string>
#include <vector>

typedef std::set<std::string> List;
class WhiteDB {
public:
	void Add(Date, std::string);
	bool Del(Date);
	bool Del(std::string);
	std::string Find(Date);
	std::string Print();
	std::string GetLog() const;
	std::string GetLastLog() const;
private:
	std::map< Date, List > db;
	std::vector<std::string> log;
};