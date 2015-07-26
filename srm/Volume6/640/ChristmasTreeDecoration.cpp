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
const int MAXN = 100;

class ChristmasTreeDecoration {
	int pnt[MAXN];
	int getP(int x) {
		if (pnt[x] == x) return x;
		return pnt[x] = getP(pnt[x]);
	}
public:
	int solve(vector <int>, vector <int>, vector <int>);
};

int ChristmasTreeDecoration::solve(vector <int> col, vector <int> x, vector <int> y) {
	int n = col.size();
	for (int i = 0; i < n; i ++) {
		pnt[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < x.size(); i ++) {
		int u = x[i] - 1, v = y[i] - 1;
		if (col[u] == col[v] || getP(u) == getP(v)) continue;
		pnt[getP(u)] = getP(v);
		ans ++;
	}
	return n - ans - 1;
}	

//Powered by [KawigiEdit] 2.0!
