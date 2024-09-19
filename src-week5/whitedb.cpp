#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "date.hpp"
#include "whitedb.hpp"

void WhiteDB::Add(Date date, std::string event) {
	if (date.LastError().empty()) {
		db[date].insert(event);
	}
	else {
		log.push_back(date.LastError());
	}
}
bool WhiteDB::Del(Date date) {
	if (db.contains(date)) {
		log.push_back("Deleted " + std::to_string(db[date].size()) + " events");
		db.erase(date);
		return true;
	}
	else {
		log.push_back("Deleted 0 events");
	}
	return false;
}
bool WhiteDB::Del(std::string event) {
	for (auto& record : db) {
		auto iter = std::find(record.second.begin(), record.second.end(), event);
		if (iter != record.second.end())
		{
			record.second.erase(iter);
			log.push_back("Deleted successfully");
			if (record.second.empty()) {
				db.erase(record.first);
			}
			return true;
		}
	}
	log.push_back("Event not found");
	return false;
}
std::string WhiteDB::Find(Date date) {
	std::string result;
	if (db.find(date) != db.end()) {
		for (auto& event : db[date]) {
			result.append(event);
		}
		log.push_back(result);
		return result;
	}
	result.append("Events at day " + date.ToString() + " not found");
	log.push_back(result);
	return result;
}
std::string WhiteDB::Print() {
	std::string result;
	for (auto& record : db) {
		for (auto& event : record.second) {
			result.append(record.first.ToString() + " " + event + "\n");
		}
	}
	if (!result.empty()) { result.pop_back(); };
	log.push_back(result);
	return result;
}
std::string WhiteDB::GetLog() const {
	std::string result;
	for (auto& record : log) {
		result.append(record + "\n");
	}
	return result;
}std::string WhiteDB::GetLastLog() const {
	return log.back();
}