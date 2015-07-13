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
const int MAXN = 60;
const int INF = 0x3fffff;

class TheKingsTree {
	vector<list<int> > tree;
	vector<vector<int> > ret1, ret0;
	vector<int> sz;
	int n;
	void dfs(int x, int p) {
		ret1[x].resize(MAXN);
		ret0[x].resize(MAXN);
		for (int i = 0; i < MAXN; i ++) ret1[x][i] = ret0[x][i] = INF;
		ret1[x][1] = 1; ret0[x][0] = 1;
		sz[x] = 1;
		for (auto v: tree[x]) {
			if (v == p) continue;
			dfs(v, x);
			vector<int> t1 = ret1[x], t0 = ret0[x];
			ret1[x].assign(MAXN, INF);
			ret0[x].assign(MAXN, INF);
			for (int i = 0; i < MAXN; i ++) for (int j = 0; j <= i && j <= sz[v]; j ++) {
				ret1[x][i] = min(ret1[x][i], t1[i - j] + ret1[v][j] + j);
				ret1[x][i] = min(ret1[x][i], t1[i - j] + ret0[v][j] + j);
				ret0[x][i] = min(ret0[x][i], t0[i - j] + ret1[v][j] + sz[v] - j);
				ret0[x][i] = min(ret0[x][i], t0[i - j] + ret0[v][j] + sz[v] - j);
			}
			sz[x] += sz[v];
		}
	}
public:
	int getNumber(vector <int>);
};

int TheKingsTree::getNumber(vector <int> p) {
	n = p.size() + 1;
	tree.resize(n);
	ret1.resize(n);
	ret0.resize(n);
	sz.resize(n);
	for (int i = 1; i < n; i ++) {
		tree[i].push_back(p[i - 1]);
		tree[p[i - 1]].push_back(i);
	}
	dfs(0, -1);
	int ans = INF;
	for (int i = 0; i < MAXN; i ++) ans = min(ans, min(ret0[0][i], ret1[0][i]));
	return ans;
}
//Powered by [KawigiEdit] 2.0!
