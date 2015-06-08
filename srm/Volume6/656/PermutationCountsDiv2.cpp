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
typedef long long ll;

using namespace std;
const int maxn = 210;
const int MOD = 1000000007;

class PermutationCountsDiv2 {
	int mk[maxn];
	int ans[maxn][maxn];
	int c[maxn][maxn], m;
	int C(int x, int y) {
		if (c[x][y] != -1)
			return c[x][y];
		if (x < y || y < 0) return 0;
		if (x == y || y == 0) return c[x][y] = 1;
		return c[x][y] = (C(x - 1, y) + C(x - 1, y - 1)) % MOD;
	}
	int calc(int b, int e) {
		if (ans[b][e] != -1) 
			return ans[b][e];
		if (e - b <= 1) return ans[b][e] = 1;
		ans[b][e] = 0;
		for (int i = b - 1; i < e - 1; i ++) if (i == b - 1 || mk[i]) {
			if (i + 1 < e - 1 && mk[i + 1]) continue;
			ll f = C(e - b - 1, i + 1 - b);
			ans[b][e] = (ans[b][e] +  (f * calc(b, i + 1) % MOD) * calc(i + 2, e) % MOD) % MOD;
		}
		return ans[b][e];
	}
public:
	int countPermutations(int, vector <int>);
};

int PermutationCountsDiv2::countPermutations(int N, vector <int> pos) {
	m = pos.size();
	for (int i = 0; i < m; i ++) mk[pos[i] - 1] = 1;
	memset(ans, 0xff, sizeof(ans));
	memset(c, 0xff, sizeof(c));
	return calc(0, N);
}
