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
#include <memory>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int MOD = 1000000007;
const int maxn = 60;

class OkonomiyakiParty {
	int c[maxn][maxn];
	int C(int x, int y) {
		if (y < 0 || y > x) return 0;
		if (y == 0 || x == y) return 1;
		if (c[x][y] != -1)
			return c[x][y];
		return c[x][y] = (C(x - 1, y - 1) + C(x - 1, y)) % MOD;
	}
public:
	int count(vector <int>, int, int);
};

int OkonomiyakiParty::count(vector <int> p, int M, int K) {
	sort(p.begin(), p.end());
	int ans = 0;
	memset(c, 0xff, sizeof(c));
	for (int i = 0; i < p.size(); i ++) {
		int b = p.size();
		for (int j = i + 1; j < p.size(); j ++) {
			if (p[j] - p[i] > K) {
				b = j; 
				break;
			}
		}
		ans = (ans + C(b - i - 1, M - 1)) % MOD;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
