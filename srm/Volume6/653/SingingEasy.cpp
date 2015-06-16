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
#include <memory>
#include <cstring>

using namespace std;
const int maxn = 2010;
const int inf = 0x3fffffff;

class SingingEasy {
	int ans[maxn][maxn];
	int n;
	int c[maxn];
	void update(int &x, int y, int s, int t) {
		int dis = 0;
		if (t && s != (n + 1)) dis = abs(c[s] - c[t]);
		if (x == -1 || x > y + dis) 
			x = y + dis;
	}
public:
	int solve(vector <int>);
};

int SingingEasy::solve(vector <int> p) {
	n = p.size();
	memset(ans, 0xff, sizeof(ans));
	for (int i = 1; i <= n; i ++) c[i] = p[i - 1];
	ans[0][0] = 0;
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) if (ans[i][j] != -1) {
			if (i >= j) {
				update(ans[i + 1][j], ans[i][j], i + 1, i);
				update(ans[i][i + 1], ans[i][j], i + 1, j);
			} else {
				update(ans[i][j + 1], ans[i][j], j + 1, j);
				update(ans[j + 1][j], ans[i][j], j + 1, i);
			}
		}
	}
	int ret = inf;
	for (int i = 0; i <= n + 1; i ++) {
		if (ans[i][n + 1] != -1) ret = min(ans[i][n + 1], ret);
		if (ans[n + 1][i] != -1) ret = min(ans[n + 1][i], ret);
	}
	return ret;
}


//Powered by [KawigiEdit] 2.0!
