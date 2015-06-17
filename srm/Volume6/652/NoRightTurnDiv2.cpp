#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <memory>
#include <cstring>
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

class NoRightTurnDiv2 {
	int mk[60], n;
	int x[60], y[60];
	long long cross(int t0, int t1, int t2) {
		return (long long)(x[t1] - x[t0]) * (y[t2] - y[t0]) - (x[t2] - x[t0]) * (y[t1] - y[t0]);
	}
	int check(int s, vector<int> &ans) {
		ans.resize(0);
		memset(mk, 0xff, sizeof(mk));
		vector<int> t;
		t.push_back(s);
		mk[s] = 0;
		int cnt = 0, now = s;
		while (cnt < n - 1) {
			int found = -1;
			for (int i = 0; found == -1 && i < n; i ++) if(-1 == mk[i]) {
				int ok = 1;
				for (int j = 0; ok && j < n; j ++) if (-1 == mk[j] && i != j) {
					if (cross(now, i, j) < 0) ok = 0;
				}
				if (ok) {
					for (int j = 0; ok && j < cnt; j ++) {
						if (cross(now, i, t[j]) * cross(now, i, t[j + 1]) < 0
							 && cross(t[j], t[j + 1], now) * cross(t[j], t[j + 1], i) < 0) ok = 0;
					}
				}
				if (ok) found = i;
			}
			if (found == -1) return 0;
			cnt ++;
			mk[found] = 0;
			now = found;
			t.push_back(found);
		}
		ans = t;
		return 1;
	}
public:
	vector <int> findPath(vector <int>, vector <int>);
};

vector <int> NoRightTurnDiv2::findPath(vector <int> X, vector <int> Y) {
	n = X.size();
	for (int i = 0; i < n; i ++) {
		x[i] = X[i];
		y[i] = Y[i];
	}
	vector<int> ans(n);
	for (int i = 0; i < n; i ++) {
		if(check(i, ans)) break;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
