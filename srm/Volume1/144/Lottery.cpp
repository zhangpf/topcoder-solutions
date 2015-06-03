// BEGIN CUT HERE

// END CUT HERE
#line 5 "Lottery.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
struct tt {
	ll p;
	string name;
	int operator < (const tt &other) const {
		if (p == other.p) 
			return name < other.name;
		return p < other.p;
	}
}x[50];
class Lottery {
	
	ll C(int x, int y) {
		ll ans = 1;
		for (int i = 0; i < y; i++) {
			ans *= (x - i);
			ans /= (i + 1);
		}
		return ans;
	}
	ll A(int x, int y) {
		ll ans = 1;
		for (int i = 0; i < y; i++) {
			ans *= (x - i);
		}
		return ans;
	}
	ll P(int x, int y) {
		ll ans = 1;
		for (int i = 0; i < y; i++) ans *= x;
		return ans;
	}
	
	public:
	vector <string> sortByOdds(vector <string> rules) {
		int n = rules.size();
		for (int i = 0; i < n; i++) {
			int k = rules[i].find_first_of(':');
			x[i].name = rules[i].substr(0, k);
			stringstream sin(rules[i].substr(k+1));
			int ch, b;
			char s, u;
			sin>>ch>>b>>s>>u;
			if (u == 'T' && s == 'T') x[i].p = C(ch, b);
			else if (u == 'T' && s == 'F') x[i].p = A(ch, b);
			else if (u == 'F' && s == 'T') x[i].p = C(ch - 1 + b, b);
			else x[i].p = P(ch, b);
		}
		sort(x, x+n);
		vector<string> ans;
		for (int i = 0; i < n; i++) ans.push_back(x[i].name);
		return ans;
	}
};

