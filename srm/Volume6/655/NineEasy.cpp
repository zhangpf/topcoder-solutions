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

class NineEasy {
	int n, m;
	int encode (vector<int> x) {
		int ret = 0;
		for (int i = 0; i < n; i ++) {
			ret = (9 * ret) + x[i];
		}
		return ret;
	}
	vector<int> decode(int x) {
		vector<int> ret;
		for (int i = n; i >= 1; i --) {
			ret.push_back(x % 9);
			x /= 9;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
	int s[100010];
	int keep[100010][5];
	int nxt[32][100010][9], nxts[100010][9];
	int ans[2][100010];
	int num;
	void encodeAll(int d, vector<int> now) {
		if (d == n) {
			for (int i = 0; i < n; i ++) keep[num][i] = now[i];
			s[num ++] = encode(now);
			return;
		}
		for (int i = 0; i < 9; i ++) {
			now[d] = i;
			encodeAll(d + 1, now);
		}
	}
public:
	int count(int, vector <int>);
};

int NineEasy::count(int N, vector <int> d) {
	sort(d.begin(), d.end());
	n = N; num = 0;
	m = d.size();
	vector<int> st(n);
	encodeAll(0, st);
	for (int i = 0; i < num; i ++) for (int j = 0; j < 9; j ++) {
		for (int s = 0; s < (1 << n); s ++) {
			int f = 0;
			for (int t = 0; t < n; t ++) if (s & (1 << t)) {
				f = 9 * f + (j + keep[i][t]) % 9;
			} else f = 9 * f + keep[i][t];
			nxt[s][i][j] = f;
		}
	}
	memset(ans, 0, sizeof(ans));
	ans[0][0] = 1;
	int * p1 = ans[0], * p2 = ans[1], tmp;
	for (int i = 0; i < m; i ++) {
		swap (p1, p2);
		if (i == 0 || d[i] != d[i - 1]) {
			int now = d[i];
			for (int j = 0; j < num; j ++) for (int k  = 0; k < 9; k ++) nxts[j][k] = nxt[now][j][k];
		}
		for (int j = 0; j < num; j ++) if (p2[j]) {
			for (int k = 0; k < 9; k ++) {
				tmp = p1[nxts[j][k]];
				if (k == 0) {
					tmp += p2[j];
					if (tmp >= MOD) tmp -= MOD;
				}
				tmp += p2[j];
				if (tmp >= MOD) tmp -= MOD;
				p1[nxt[d[i]][j][k]] = tmp;
			}
			p2[j] = 0;
		}
	}
	return p1[0];
}

//Powered by [KawigiEdit] 2.0!
