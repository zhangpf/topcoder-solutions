#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class RangeGame {
	vector<vector<pair<int, int> > > s;
	vector<int> mk;
	vector<pair<int, int> > parse(string ss) {
		stringstream sin(ss);
		vector<pair<int, int> > ans;
		string str;
		int low, high;
		char c;
		while (sin >> str) {
			stringstream pin(str);
			pin >> low;
			if (pin >> c >> high);
			else high = low;
			ans.push_back(make_pair(low, high));
		}
		return ans;
	}
	int cross(const vector<pair<int, int> > &s1, const vector<pair<int, int> > &s2) {
		for (auto it1: s1) for (auto it2: s2) {
			if (it1.first <= it2.second && it2.first <= it1.second) return 1;
		}
		return 0;
	}
	int calc(int x) {
		int ans = 0;
		for (int j = 0; j < s.size(); j ++) if (mk[j] == 0) {
			for (auto it: s[j]) {
				if (it.first <= x && it.second >= x) {
					ans ++; break;
				}
			}
		}
		return ans;
	}
public:
	vector <int> bestDoors(vector <string>, vector <string>);
};

vector <int> RangeGame::bestDoors(vector <string> p, vector <string> h) {
	int n = p.size();
	s.resize(n);
	mk.resize(n);
	for (int i = 0; i < n; i ++) s[i] = parse(p[i]);
	vector<int> ans;
	for (int i = 0; i <= h.size(); i ++) {
		int cnt = 0, v = 1;
		for (int j = 0; j < n; j ++) if (!mk[j]) {
			for (auto it: s[j]) {
				int tmp = calc(it.first);
				if (tmp > cnt || (cnt == tmp && v > it.first)) {
					cnt = tmp;
					v = it.first;
				}
			}
		}
		ans.push_back(v);
		if (i == h.size()) break;
		vector<pair<int, int> > hint = parse(h[i]);
		for (int j = 0; j < n; j ++) if (!mk[j]) {
			if (cross(hint, s[j])) mk[j] = 1;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
