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
#include <memory>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 60;
const int inf = 0x3fffff;

class WordParts {
	int ans[maxn][maxn];
	int prefix(int x, int y) {
		int len = y - x;
		if (len > s1.length()) return 0;
		for (int i = 0; i < len; i ++) if (s1[i] != s2[x + i]) return 0;
		return 1;
	}
	int suffix(int x, int y) {
		int len = y - x;
		int ls1 = s1.length();
		if (len > ls1) return 0;
		for (int i = 0; i < len; i ++) if (s1[ls1 - len + i] != s2[x + i]) return 0;
		return 1;
	}
	string s1, s2;
	int calc(int x, int y) {
		if (ans[x][y] != -1)
			return ans[x][y];
		ans[x][y] = inf;
		if (x >= y) ans[x][y] = 0;
		else if (prefix(x, y) || suffix(x, y)) ans[x][y] = 1;
		else {
			for (int i = x + 1; i < y; i ++) {
				ans[x][y] = min(ans[x][y], calc(x, i) + calc(i, y));
			}
		}
		return ans[x][y];
	}
public:
	int partCount(string, string);
};

int WordParts::partCount(string original, string compound) {
	memset(ans, 0xff, sizeof(ans));
	s1 = original;
	s2 = compound;
	int ret = calc(0, s2.length());
	if (ret == inf) ret = -1;
	return ret;
}

//Powered by [KawigiEdit] 2.0!
