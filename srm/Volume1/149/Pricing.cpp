#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <memory>
#include <cstring>
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
const int maxn = 110;

class Pricing {
	int t[maxn];
	int n;
	int ans[maxn][maxn][5];
	int calc(int x, int y, int z) {
		if (ans[x][y][z] != -1)
			return ans[x][y][z];
		ans[x][y][z] = t[x] * (y - x);
		for (int i = x + 1; i < y; i ++) ans[x][y][z] = max(ans[x][y][z], calc(i, y, z));
		for (int i = 1; i < z; i ++) {
			for (int j = x + 1; j < y; j ++) {
				ans[x][y][z] = max(ans[x][y][z], calc(x, j, i) + calc(j, y, z - i));
			}
		}
		return ans[x][y][z];
	}
public:
	int maxSales(vector <int>);
};

int Pricing::maxSales(vector <int> p) {
	sort(p.begin(), p.end());
	memset(ans, 0xff, sizeof(ans));
	n = p.size();
	for (int i = 0; i < n; i ++) t[i] = p[i];
	printf("%d %d\n", calc(1, n - 1, 3), calc(n - 1, n, 1));
	return calc(0, n, 4);
}

//Powered by [KawigiEdit] 2.0!
