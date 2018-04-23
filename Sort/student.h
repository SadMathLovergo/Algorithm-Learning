#pragma once
#include <iostream>
using namespace std;

struct student {
	string name;
	int score;
	bool operator<(const student &otherStudent) {
		return score < otherStudent.score;
	}
};
