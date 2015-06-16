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
const int maxn = 2010;
const int MOD = 1000000007;

class RockPaperScissorsMagicEasy {
	int c[maxn][maxn];
	int p[maxn];
	int C(int x, int y) {
		if (c[x][y] != -1)
			return c[x][y];
		if (y > x || x < 0) return 0;
		if (y == x || y == 0) return c[x][y] = 1;
		c[x][y] = C(x - 1, y) + C(x - 1, y - 1);
		if (c[x][y] >= MOD) c[x][y] -= MOD;
		return c[x][y];
	}
	int P(int x) {
		if (p[x] != -1) 
			return p[x];
		if (x < 0) return 0;
		if (x == 0) return p[x] = 1;
		else {
			p[x] = P(x - 1) * 2;
			if (p[x] >= MOD) p[x] -= MOD;
			return p[x];
		}
	}
public:
	int count(vector <int>, int);
};

int RockPaperScissorsMagicEasy::count(vector <int> card, int score) {
	memset(c, 0xff, sizeof(c));
	memset(p, 0xff, sizeof(p));
	return (int)((long long) C(card.size(), score) * P(card.size() - score) % MOD);
}

//Powered by [KawigiEdit] 2.0!
