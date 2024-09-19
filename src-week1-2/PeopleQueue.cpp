#include <vector>
#include "PeopleQueue.hpp"
//0 - quiet, 1 - worry
PeopleQueue::PeopleQueue() {
	queue.clear();
	worried=0;
}
void PeopleQueue::Come(int size) {
	if (size > 0) {
		for (int i = 0; i < size; i++)queue.push_back(0);
	}
	else if (size < 0) {
		for (int i = 0; i > size; i--) {
			if (queue.back()) {
				worried--;
			}
			queue.pop_back();
		}
	}
}
void PeopleQueue::Worry(int i) {
	if (queue[i] == 0) {
		queue[i] = 1;
		worried++;
	}
}
void PeopleQueue::Quiet(int i) {
	if (queue[i] == 1) {
		queue[i] = 0;
		worried--;
	}
}
int PeopleQueue::WorryCount() {
	return worried;
}