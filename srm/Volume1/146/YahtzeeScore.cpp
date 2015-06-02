// BEGIN CUT HERE

// END CUT HERE
#line 5 "YahtzeeScore.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <map>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class YahtzeeScore {
	public:
	int maxPoints(vector <int> toss) {
		map<int, int> c;
		for (int i = 0; i < toss.size(); i++) {
			c[toss[i]] += toss[i];
		}
		int ans = 0;
		for (map<int, int>::iterator it = c.begin(); it != c.end(); it ++) {
			ans = max(ans, it->second);
		}
		return ans;
	}
};
