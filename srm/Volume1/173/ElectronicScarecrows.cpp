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
#include <cstring>
#include <memory>
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

struct Point {
	int x, y;
} pivot;

class ElectronicScarecrows {
	vector <Point> p;
	static int cross(const Point &p0, const Point &p1, const Point &p2) {
		return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
	}
	static int dissqr(const Point &p1, const Point &p2) {
		return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
	}
	static int cmp(const Point &p1, const Point &p2) {
		int c = cross(pivot, p1, p2);
		return c < 0 || (c == 0 && dissqr(pivot, p1) < dissqr(pivot, p2));
	}
	int ans[MAXN][MAXN];
public:
	double largestArea(vector <int>, vector <int>, int);
};

double ElectronicScarecrows::largestArea(vector <int> x, vector <int> y, int m) {
	int n = x.size();
	p.resize(n);
	int ret = 0;
	for (int i = 0; i < n; i ++) p[i].x = x[i], p[i].y = y[i];
	for (int i = 0; i < n; i ++) {
		pivot = p[i];
		vector <Point> rem;
		for (int j = 0; j < n; j ++) {
			if (p[i].y < p[j].y || (p[i].y == p[j].y && p[i].x < p[j].x)) rem.push_back(p[j]);
		}
		sort(rem.begin(), rem.end(), cmp);
		memset(ans, 0, sizeof(ans));
		for (int j = 1; j < rem.size(); j ++) {
			for (int k = 3; k <= m; k ++) {
				for (int l = 0; l < j; l ++) {
					ans[j][k] = max(ans[j][k], ans[l][k - 1] + abs(cross(p[i], rem[j], rem[l])));
				}
				if (k <= m) ret = max(ret, ans[j][k]);
			}
		}
	}
	return ret / 2.;
}
//Powered by [KawigiEdit] 2.0!
