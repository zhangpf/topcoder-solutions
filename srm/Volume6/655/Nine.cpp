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
#include <memory>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MOD = 1000000007;

class Nine {
	int n, m;
	int ans[2][100010];
	int num;
	int c[5010];
	int getP(int x, int d) {
		if (c[x] != -1) {
			return (c[x] + (d == 0)) % MOD;
		}
		//printf ("%d %d\n", x, d);
		if (x == 0) c[x] = 0;
		else c[x] = (10LL * getP(x - 1, 1) + 1) % MOD;
		return (c[x] + (d == 0)) % MOD;
	}
public:
	int count(int, vector <int>);
};

int Nine::count(int N, vector <int> d) {
	sort(d.begin(), d.end());
	n = N; 
	num = 1;
	m = d.size();
	memset(c, 0xff, sizeof(c));
	memset(ans, 0, sizeof(ans));
	ans[0][0] = 1;
	int * p1 = ans[0], * p2 = ans[1];
	int cur = -1;
	for (int i = 0; i < n; i ++) num *= 9;
	int newV[5];
	for (int i = 0; i < m; i ++) {
		int len = 0;
		if (i == m - 1 || d[i] != d[i + 1]) {
			len = i - cur;
			cur = i;
		} else continue;
		swap(p1, p2);
		for (int k = 0; k < 9; k ++) {
			int f = getP(len, k);
			for (int j = 0; j < num; j ++) if (p2[j]) {
				int b = j, e = 0; 
				for (int t = n - 1; t >= 0; t --) {
					e = b % 9;
					if ((1 << t) & d[i]) e += k;
					if (e >= 9) e -= 9;
					newV[t] = e;
					b /= 9;
				}
				e = 0;
				for (int t = 0; t < n; t ++) {
					e = 9 * e + newV[t];
				}
				p1[e] = ((long long)f * p2[j] + p1[e]) % MOD;
			}
		}
		memset(p2, 0, sizeof(int) * num);
	}
	return p1[0];
}
//Powered by [KawigiEdit] 2.0!
