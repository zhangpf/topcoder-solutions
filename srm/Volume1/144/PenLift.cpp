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
#include <memory>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 10010;

class PenLift {
	int x1[maxn], x2[maxn], y1[maxn], y2[maxn];
	int x[maxn], y[maxn];
	int c[maxn];
	int lenx, leny;
	int n;
	int getX(int tx) {
		return lower_bound(x, x + lenx, tx) - x;
	}
	int getY(int ty) {
		return lower_bound(y, y + leny, ty) - y;
	}
	int id(int x, int y) {
		return x * leny + y;
	}
	int pnt[maxn];
	int d[maxn], f[maxn];
	int getP(int x) {
		if (x == pnt[x]) return x;
		return pnt[x] = getP(pnt[x]);
	}
	int mk[110][110][2];
public:
	int numTimes(vector <string>, int);
};

int PenLift::numTimes(vector <string> segments, int N) {
	n = segments.size(); lenx = leny = 0;
	memset(mk, 0, sizeof(mk));
	for (int i = 0; i < n; i ++) {
		stringstream sin(segments[i]);
		sin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		x[lenx++] = x1[i];
		x[lenx++] = x2[i];
		y[leny++] = y1[i];
		y[leny++] = y2[i];
	}
	sort(x, x + lenx);
	lenx = unique(x, x + lenx) - x;
	sort(y, y + leny);
	leny = unique(y, y + leny) - y;
	memset(c, 0, sizeof(c));
	memset(d, 0, sizeof(d));
	memset(f, 0, sizeof(f));
	
	for (int i = 0; i < lenx * leny; i ++) pnt[i] = i;
	
	for (int i = 0; i < n; i ++) {
		int a1 = getX(x1[i]), b1 = getY(y1[i]);
		int a2 = getX(x2[i]), b2 = getY(y2[i]);
		//printf("%d %d %d %d\n", a1, a2, b1, b2);
		if (a1 > a2) swap(a1, a2);
		if (b1 > b2) swap(b1, b2);
		for (int j = a1; j < a2; j ++) {
			int pu = id(j, b1);
			int pv = id(j+1, b1);
			if (mk[j][b1][0]) continue;
			mk[j][b1][0] = 1;
			c[pu] ++; c[pv] ++;
			pnt[getP(pu)] = getP(pv);
		}
		for (int j = b1; j < b2; j ++) {
			int pu = id(a1, j);
			int pv = id(a1, j+1);
			if (mk[a1][j][1]) continue;
			mk[a1][j][1] = 1;
			c[pu] ++; c[pv] ++;
			pnt[getP(pu)] = getP(pv);
		}
	}
	int cnt = 0;
	for (int i = 0; i < lenx; i ++) {
		for (int j = 0; j < leny; j++) if(c[id(i,j)]) {
			printf("%d %d\n", getP(id(i, j)), c[id(i, j)]);
			d[getP(id(i, j))] += (c[id(i, j)] & 1);
			f[getP(id(i, j))] ++;
		}
	}
	for (int i = 0; i < lenx; i ++) {
		for (int j = 0; j < leny; j++) {
			int u = id(i, j);
			if (getP(u) != u || f[u] == 0) continue;
			if ((N & 1) && d[u] > 2) {
				cnt += d[u] / 2;
			} else cnt ++;
		}
	}
	return cnt - 1;
}
//Powered by [KawigiEdit] 2.0!
