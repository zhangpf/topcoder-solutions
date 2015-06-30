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

const int maxn = 51;
const int maxm = 301;
const int INF = 0x3fffffff;
using namespace std;

class GoldMine {
	vector<int> c[maxn];
	vector<int> ans[maxn][maxm];
	int v[maxn][maxm]; 
	int n, m;
	int calc(vector<int> &f, int w) {
		int ret = 0;
		for (int i = 0; i <= 6; i ++) {
			if (w < i) ret += 6 * f[i] * w;
			else if (w == i) ret += 5 * f[i] * w;
			else ret += f[i] * (5 * i - 2 * (w - i));
		}
		return ret;
	}
public:
	vector <int> getAllocation(vector <string>, int);
};

vector <int> GoldMine::getAllocation(vector <string> mines, int miners) {
	n = mines.size();
	for (int i = 0; i < n; i ++) {
		stringstream sin(mines[i]);
		string s;
		for (int j = 0; j <= 6; j ++) {
			sin >> s;
			int x = (s[0] - '0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
			c[i].push_back(x);
		}
	}
	m = miners;
	for (int i = 0; i <= n; i ++) for (int j = 0; j <= m; j ++) v[i][j] = -INF;
	v[0][0] = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j <= m && j <= 6 * i; j ++) if (v[i][j] > -INF) {
			for (int k = 0; k <= 6 && j + k <= m; k ++) {
				int t = calc(c[i], k);
				if (v[i][j] + t >= v[i + 1][j + k]) {
					v[i + 1][j + k] = v[i][j] + t;
					ans[i + 1][j + k] = ans[i][j];
					ans[i + 1][j + k].push_back(k);
				}
			}
		}
	}
	return ans[n][m];
}
//Powered by [KawigiEdit] 2.0!
