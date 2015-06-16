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
typedef long long ll;

const ll inf = 0x3ffffffffffffLL;
using namespace std;

class TheGridDivOne {
	int n, m;
	class point {
	public:
		int x, y;
		point(int _x, int _y) {
			x = _x;
			y = _y;
		}
		point() {
			x = 0; 
			y = 0;
		}
	};
	static int equal (const point &my, const point &other) {
		return other.x == my.x && other.y == my.y;
	}
	static bool cmp (const point &my, const point &other) {
		return my.x < other.x || (my.x == other.x && my.y < other.y);
	}
	int in(int x, int y, int z) {
		return (x <= y && x >= z) || (x <= z && x >= y);
	}
	point p[500];
	ll dis[500][500];
public:
	int find(vector <int>, vector <int>, int);
};

int TheGridDivOne::find(vector <int> X, vector <int> Y, int K) {
	n = X.size();
	m = 0;
	for (int i = 0; i < n; i++) {
		for (int k = -1; k <= 1; k ++) {
			for (int j = -1; j <= 1; j ++) {
				int tx = X[i] + k;
				int ty = Y[i] + j;
				int ok = 1;
				for (int s = 0; ok && s < n; s ++) {
					if (tx == X[i] && ty == Y[i]) ok = 0;
				}
				if (ok) p[m++] = point(tx, ty);
			}
		}
	}
	p[m++] = point(0, 0);
	sort(p, p + m, cmp);
	m = unique(p, p + m, equal) - p;
	int ch = 0;
	for (int i = 0; i < m; i++) if (p[i].x == 0 && p[i].y == 0) ch = i;
	memset(dis, 0, sizeof(dis));
	
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			int ok = 1;
			for (int k = 0; ok && k < m; k ++) if (i != k && j != k) {
				if (in(p[k].x, p[j].x, p[i].x) && in(p[k].y,  p[j].y, p[i].y)) ok = 0;
			}
			for (int k = 0; ok && k < n; k ++) {
				if (in(X[k], p[j].x, p[i].x) && in(Y[k], p[j].y, p[i].y)) ok = 0;
			}
			if (ok) {
				dis[i][j] = (long long)abs(p[i].x - p[j].x) + abs(p[i].y - p[j].y);
				dis[j][i] = dis[i][j];
			} else {
				dis[i][j] = inf;
				dis[j][i] = inf;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k ++) {
				if (dis[j][k] > dis[j][i] + dis[i][k]) 
					dis[j][k] = dis[j][i] + dis[i][k];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < m; i++) {
		if (dis[ch][i] <= K) {
			//printf("%d %d %d", p[i].x, p[i].y, dis[ch][i]);
			int ret = p[i].x + (K - dis[ch][i]);
			for (int j = 0; j < n; j++) {
				if (p[i].y == Y[j] && X[j] > p[i].x && K - dis[ch][i] + p[i].x >= X[j])
					ret = min(ret, X[j] - 1);
			}
			//printf(" %d\n", ret);
			ans = max(ans, ret);
		}
	}
	return min(ans, K);
}

//Powered by [KawigiEdit] 2.0