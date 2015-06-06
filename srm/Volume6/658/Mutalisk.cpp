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

using namespace std;
const int maxn = 141;
const int maxt = 21;

class Mutalisk {
	int n, y[maxt];
	int ans[maxt][maxn][maxn];
	int check(int x) {
		memset(ans, 0xff, sizeof(ans));
		ans[0][x][x] = x;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= x; j ++) for (int k = 0; k <= x; k ++) if(ans[i][j][k] >= 0) {
				for (int s = min(j, (y[i] + 8) / 9); s >= 0; s --) 
					for (int t = min(k, (max((y[i] - 9 * s), 0) + 2) / 3); t >= 0; t --) {
						int f = max(0, y[i] - s * 9 - t * 3);
						if (f + s + t <= x && f <= ans[i][j][k]) {
							ans[i+1][j-s][k-t] = max(ans[i+1][j-s][k-t], ans[i][j][k] - f);
						}
					}
			}
		}
		for (int i = 0; i <= x; i ++) for (int j = 0; j <= x; j ++) if(ans[n][i][j] != -1) return 1;
		return 0;
	}
public:
	int minimalAttacks(vector <int>);
};

int Mutalisk::minimalAttacks(vector <int> T) {
	n = T.size();
	for (int i = 0; i < n; i ++) y[i] = T[i];
	int low = 1, high = 7 * n; 
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}
	return low;
}
//Powered by [KawigiEdit] 2.0!
