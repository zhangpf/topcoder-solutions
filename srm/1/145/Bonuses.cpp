// BEGIN CUT HERE

// END CUT HERE
#line 5 "Bonuses.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Bonuses {
	public:
	vector <int> getDivision(vector <int> points) {
		int n = points.size(), sum = 0;
		for (int i = 0; i < n; i ++) {
			sum += points[i];
		}
		vector<int> ans, b;
		int total = 100;
		for (int i = 0; i < n; i ++) {
			ans.push_back(points[i] * 100 / sum);
			total -= ans[i];
			b.push_back(0);
		}
		while (total > 0) {
			int now = -1;
			for (int i = 0; i < n; i ++) {
				if (b[i] == 0 && (now == -1 || points[now] < points[i])) now = i;
			}
			ans[now] ++;
			b[now] = 1;
			total --;
		}
		return ans;
	}
};
