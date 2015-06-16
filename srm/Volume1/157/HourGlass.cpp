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
#include <cassert>

using namespace std;
const int maxn = 51;
const int qlen = 1250100;
const int inf = 100000;

class HourGlass {
	int c[maxn][maxn][maxn * 10];
	int q1[qlen], q2[qlen], q3[qlen];
	int check(int s1, int s2, int s3, int &t1, int &t2, int &t3) {
		int v = inf;
		if (s1) v = min(v, s1);
		if (s2) v = min(v, s2);
		if (v == inf) v = 0;
		if (s3 + v >= maxn * 10) return 0;
		if (s1) s1 -= v;
		if (s2) s2 -= v;
		s3 += v;
		if (c[s1][s2][s3]) return 0;
		t3 = s3;
		t1 = s1; t2 = s2;
		return 1;
	}
public:
	vector <int> measurable(int, int);
};

vector <int> HourGlass::measurable(int g1, int g2) {
	q1[0] = 0, q2[0] = 0, q3[0] = 0;
	memset(c, 0, sizeof(c));
	c[0][0][0] = 1;
	int cur = 0, tail = 1;
	while (cur < tail) {
		int s1 = q1[cur], s2 = q2[cur], s3 = q3[cur];
		cur ++;
		int t1, t2, t3;
		if (check(s1, s2, s3, t1, t2, t3)) {
			q1[tail] = t1; q2[tail] = t2; q3[tail] = t3;
			tail ++;
			c[t1][t2][t3] = 1;
		} 
		if (check(g1 - s1, s2, s3, t1, t2, t3)) {
			q1[tail] = t1, q2[tail] = t2, q3[tail] = t3;
			tail ++;
			c[t1][t2][t3] = 1;
		}
		if (check(g1 - s1, g2 - s2, s3, t1, t2, t3)) {
			q1[tail] = t1, q2[tail] = t2, q3[tail] = t3;
			tail ++;
			c[t1][t2][t3] = 1;
		}
		if (check(s1, g2 - s2, s3, t1, t2, t3)) {
			q1[tail] = t1, q2[tail] = t2, q3[tail] = t3;
			tail ++;
			c[t1][t2][t3] = 1;
		}
	}
	vector<int> ans;
	int cnt = 0;
	for (int k = 1; cnt < 10; k ++) {
		int ok = 0;
		for (int i = 0; !ok && i <= 50; i ++) {
			for (int j = 0; !ok && j <= 50; j ++) if (c[i][j][k]) {
				cnt ++;
				ok = 1;
				ans.push_back(k);
			}
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
