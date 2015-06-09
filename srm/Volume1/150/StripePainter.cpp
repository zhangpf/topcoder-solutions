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
const int maxn = 60;

class StripePainter {
	int n, c[maxn];
	int ans[maxn][maxn][27];
	int calc(int l, int r, int b) {
		if (ans[l][r][b] != -1)
			return ans[l][r][b];
		if (r - l == 1) {
			if (b == c[l]) ans[l][r][b] = 0;
			else ans[l][r][b] = 1;
		} else {
			ans[l][r][b] = calc(l + 1, r, c[l]);
			if (c[l] != b) ans[l][r][b] ++;
			ans[l][r][b] = min(ans[l][r][b], calc(l, r - 1, c[r - 1]) + (c[r - 1] != b));
			for (int i = l + 1; i < r; i ++) {
				ans[l][r][b] = min(ans[l][r][b], calc(l, i, b) + calc(i, r, b));
			}
		}
		return ans[l][r][b];
	}
public:
	int minStrokes(string);
};

int StripePainter::minStrokes(string s) {
	n = s.length();
	memset(ans, 0xff, sizeof(ans));
	for (int i = 0; i < n; i ++) {
		c[i] = s[i] - 'A';
	}
	return calc(0, n, 26);
}
//Powered by [KawigiEdit] 2.0!
