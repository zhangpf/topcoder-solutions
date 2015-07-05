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
const int INF = 0x3ffffff;

class TreeCutting {
	vector<int> mk;
	vector<int> value;
	vector<list<int> > g;
	int dfs(int x) {
		mk[x] = 1;
		int sum = 0, c1 = 0;
		for (int v: g[x]) {
			if (mk[v]) continue;
			int k = dfs(v);
			if (k == - INF) return -INF;
			if (k < 0) c1 ++;
			if (c1 == 1 && value[x] != -1) return -INF;
			if (c1 > 1) return -INF;
			sum += k;
		}
		int rem = sum + 1 - (value[x] == -1 ? 0 : value[x]);
		if ((value[x] != -1 || c1 == 1) && rem > 0) return -INF;
		return rem; 
	}
public:
	string can(vector <int>, vector <int>);
};

string TreeCutting::can(vector <int> par, vector <int> num) {
	int n = par.size() + 1;
	g.resize(n);
	mk.resize(n);
	value = num;
	for (int i = 0; i < n - 1; i ++) {
		g[i + 1].push_back(par[i]);
		g[par[i]].push_back(i + 1);
	}
	if (!dfs(0)) return "POSSIBLE";
	else return "IMPOSSIBLE";
}

//Powered by [KawigiEdit] 2.0!
