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
const int inf = 0x3fffffff;
const int maxn = 30;

class Jumper {
	int ans[maxn][maxn][5];
	int n;
	int q1[2010], q2[2010], q3[2010];
	int in(int x, int y) {
		return x >= 0 && y >= 0 && x < n && y < 20;
	}
	int v[maxn];
	string p[maxn];
	int ok(int x, int y, int s, int &fx, int &fy) {
		if (x == 0 || x == n - 1) {
			fx = x; fy = y;
			return 1;
		}
		char k = p[x][(y - s * v[x] + 100) % 5];
		if (k == '.') return 0;
		y += v[x];
		if (in(x, y)) {
			fx = x; fy = y;
			return 1;
		} 
		return 0;
	}
public:
	int minTime(vector <string>, vector <int>, string);
};

const int ox[5] = {0, 1, -1, 0, 0};
const int oy[5] = {0, 0, 0, -1, 1};

int Jumper::minTime(vector <string> h, vector <int> s, string r) {
	n = r.length() + 2;
	for (int i = 0; i < n; i ++) for (int j = 0; j < 20; j ++) {
		for (int k = 0; k < 5; k ++) ans[i][j][k] = inf;
	}
	for (int i = 1; i < n - 1; i ++) {
		int idx = r[n - i - 2] - '0';
		v[i] = s[idx];
		p[i] = h[idx];
	}
	ans[n - 1][0][0] = 0;
	int tail = 1, cur = 0;
	q1[0] = n - 1, q2[0] = 0, q3[0] = 0;
	int ret = inf;
	while (tail > cur) {
		int s1 = q1[cur], s2 = q2[cur], s3 = q3[cur];
		cur ++;
		if (s1 == 0) break;
		for (int i = 0; i < 5; i ++) {
			int tx = s1 + ox[i];
			int ty = s2 + oy[i];
			int fx, fy;
			if (!in(tx, ty) || !ok(tx, ty, s3, fx, fy) || ans[fx][fy][(s3 + 1) % 5] != inf) continue;
			q1[tail] = fx;
			q2[tail] = fy;
			q3[tail] = (s3 + 1) % 5;
			tail ++;
			ans[fx][fy][(s3 + 1) % 5] = ans[s1][s2][s3] + 1;
		} 
	}
	for (int i = 0; i < 20; i ++) {
		for (int j = 0; j < 5; j ++) {
			ret = min(ret, ans[0][i][j]);
		}
	}
	if (ret == inf) ret = -1;
	return ret;
}

//Powered by [KawigiEdit] 2.0!
