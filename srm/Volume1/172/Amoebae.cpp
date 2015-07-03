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

const int ox[4] = {0, 0, -1, 1};
const int oy[4] = {1, -1, 0, 0};

class Amoebae {
	int n, m;
	vector<pair<int, int> > dfs(int x, int y, vector<int> &mk, const vector<string> &s) {
		mk[x * m + y] = 1;
		vector<pair<int, int> > ans;
		ans.push_back(make_pair(x, y));
		for (int i = 0; i < 4; i ++) {
			int tx = x + ox[i];
			int ty = y + oy[i];
			if (tx < 0 || tx >= n || ty < 0 || ty >= m || s[tx][ty] != 'X' || mk[tx * m + ty]) continue;
			vector<pair<int, int> > tmp = dfs(tx, ty, mk, s);
			for (auto it: tmp) ans.push_back(it);
		}
		return ans;
	}
	vector<vector<pair<int, int> > > calc(vector<string> s) {
		vector<int> mk(n * m);
		vector<vector<pair<int, int> > > b;
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j < m; j ++) if (s[i][j] == 'X' && !mk[i * m + j]) b.push_back(dfs(i, j, mk, s));
		
		return b;
	}
	int ok(vector<pair<int, int> > x, vector<pair<int, int> > y) {
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		for (int i = 0; i < x.size(); i ++) {
			if (x[i].first - y[i].first != x[0].first - y[0].first) return 0;
			if (x[i].second - y[i].second != x[0].second - y[0].second) return 0;
		}
		return 1;
	}
	vector<pair<int, int> > rotate(vector<pair<int, int> > x) {
		for (int i = 0; i < x.size(); i ++) {
			swap(x[i].first, x[i].second);
			x[i].second *= -1;
		}
		return x;
	}
	vector<pair<int, int> > mirror(vector<pair<int, int> > x) {
		for (int i = 0; i < x.size(); i ++) x[i].second = -x[i].second;
		return x;
	}
	int check(vector<pair<int, int> > x, vector<pair<int, int> > y) {
		if (x.size() != y.size()) return 0;
		for (int i = 0; i < 4; i ++) {
			if (ok(x, y)) return 1;
			y = rotate(y);
		}
		y = mirror(y);
		for (int i = 0; i < 4; i ++) {
			if (ok(x, y)) return 1;
			y = rotate(y);
		}
		return 0;
	}
public:
	int cultureX(vector <string>, vector <string>);
};

int Amoebae::cultureX(vector <string> s1, vector <string> s2) {
	n = s1.size();
	m = s1[0].length();
	vector<vector<pair<int, int> > > t1 = calc(s1), t2 = calc(s2);
	int ans = 0;
	vector<int> mk(t2.size());
	for (int i = 0; i < t1.size(); i ++) {
		int found = -1;
		for (int j = 0; -1 == found && j < t2.size(); j ++) {
			if (!mk[j] && check(t1[i], t2[j])) found = j;
		}
		if (-1 == found) ans ++;
		else mk[found] = 1;
	}
	for (int i = 0; i < t2.size(); i ++) if (!mk[i]) ans ++;
	return ans;
}
//Powered by [KawigiEdit] 2.0!
