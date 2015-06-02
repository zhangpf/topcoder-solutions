#line 5 "ExerciseMachine.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ExerciseMachine {
	public:
	int getPercentages(string time) {
		int h = (time[0] - '0') * 10 + time[1] - '0';
		int m = (time[3] - '0') * 10 + time[4] - '0';
		int s = (time[6] - '0') * 10 + time[7] - '0';
		int ss = s + m * 60 + h * 3600;
		int ans = 0;
		//cout << ss;
		for (int i = 1; i < 100; i++) {
			if ((ss * i) % 100 == 0) ans ++;
		}
		return ans;
	}
};


// Powered by FileEdit
