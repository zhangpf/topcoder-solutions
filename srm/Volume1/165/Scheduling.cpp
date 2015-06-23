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
#include <cstring>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Scheduling {
	vector<list<int> > graph;
	int n;
	vector<int> t;
	int ans[1 << 12][13][11];
	void update(int &x, int y) {
		if (x == -1 || x > y) x = y;
	}
public:
	int fastest(vector <string>);
};

int Scheduling::fastest(vector <string> dag) {
	n = dag.size();
	t.resize(n);
	graph.resize(n);
	for (int i = 0; i < n; i ++) {
		stringstream sin(dag[i]);
		char c;
		int from;
		sin >> t[i] >> c;
		while (sin >> from) {
			sin >> c;
			graph[i].push_back(from);
		}
	}
	memset(ans, 0xff, sizeof(ans));
	ans[0][n][0] = 0;
	for (int i = 0; i < (1 << n); i ++) {
		for (int j = n; j >= 0; j --) for (int v = 0; v <= 10; v ++) if (ans[i][j][v] != -1){
			for (int k = 0; k < n; k ++) if (k != j) {
				if ((1 << k) & i) continue;
				int ok = 1;
				for (auto it: graph[k]) {
					if (!((1 << it) & i)) {
						ok = 0;
						break;
					}
				}
				if (!ok) continue;
				int ni, nj, nv, ti;
				if (v < t[k]) {
					if (j != n) ni = i | (1 << j);
					else ni = i;
					nj = k;
					nv = t[k] - v;
					ti = ans[i][j][v] + v;
				} else if (v == t[k]) {
					if (j == n) ni = i | (1 << k);
					else ni = i | (1 << k) | (1 << j);
					nj = n;
					nv = 0;
					ti = ans[i][j][v] + v;
				} else {
					ni = i | (1 << k);
					nj = j;
					nv = v - t[k];
					ti = ans[i][j][v] + t[k];
				}
				update(ans[ni][nj][nv], ti);
			}
			if (j != n) {
				update(ans[i | (1 << j)][n][0], ans[i][j][v] + v);
			}
		}
	}
	int minV = 0x3fffff;
	for (int j = 0; j <= n; j ++) for (int i = 0; i <= 10; i ++) if (ans[(1 << n) - 1][j][i] != -1) {
		minV = min(minV, ans[(1 << n) - 1][j][i] + i);
	}
	return minV;
}
//Powered by [KawigiEdit] 2.0!
