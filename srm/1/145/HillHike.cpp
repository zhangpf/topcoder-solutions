// BEGIN CUT HERE

// END CUT HERE
#line 5 "HillHike.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

const int maxn = 110;

class HillHike {
	ll ans[maxn][maxn][maxn][2];
	int land[maxn];
	int s, n, m;
	void update(int x, int y, int z, int w, ll v) {
		if (y < 0) return;
		if (y == 0 && x != 0 && x != n) return;
		if (y > m) return;
		if (z < s && y == land[z]) z++;
		if (w == 0 && y == m) w = 1;
		ans[x][y][z][w] += v;
	}
	public:
	ll numPaths(int d, int maxH, vector <int> l) {
		n = d, m = maxH;
		s = l.size();
		for (int i = 0; i < s; i++) land[i] = l[i];
		memset(ans, 0, sizeof(ans));
		ans[0][0][0][0] = 1;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j <= m; j ++) {
				for (int k = 0; k <= s; k ++) {
					for (int t = 0; t < 2; t ++) if(ans[i][j][k][t]) {
						update(i+1, j+1, k, t, ans[i][j][k][t]);
						update(i+1, j-1, k, t, ans[i][j][k][t]);
						update(i+1, j, k, t, ans[i][j][k][t]);
					}
				}
			}
		}
		return ans[n][0][s][1]; 
	}
};
