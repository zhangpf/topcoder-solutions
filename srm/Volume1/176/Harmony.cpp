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
const int INF = 0x3fffffff;

int gcd (int x, int y) {
	if (x == 0) return y;
	return gcd(y % x, x);
}

class Harmony {
	vector<int> calc(int x, int y, int z) {
		vector<int> ans;
		ans.push_back(x);
		ans.push_back(y);
		ans.push_back(z);
		vector<int> g(3);
		g[0] = x / gcd(x, y);
		g[1] = x / gcd(x, z);
		g[2] = y / gcd(y, z);
		sort(g.begin(), g.end());
		ans.push_back(g[0]); ans.push_back(g[1]); ans.push_back(g[2]);
		return ans;
	}
	int cmp(vector<int> &t1, vector<int> &t2) {
		if (t1[5] != t2[5]) return t1[5] - t2[5];
		if (t1[4] != t2[4]) return t1[4] - t2[4];
		if (t1[3] != t2[3]) return t1[3] - t2[3];
		if (t1[0] != t2[0]) return t1[0] - t2[0];
		if (t1[1] != t2[1]) return t1[1] - t2[1];
		return t1[2] - t2[2];
	}
public:
	vector <int> mostHarmonious(vector <int>);
};

vector <int> Harmony::mostHarmonious(vector <int> f) {
	int n = f.size();
	sort(f.begin(), f.end());
	vector<int> ans(6, INF);
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = j + 1; k < n; k ++) {
				vector<int> tmp = calc(f[i], f[j], f[k]);
				if (cmp(tmp, ans) < 0) ans = tmp;
			}
		}
	}
	ans.resize(3);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
