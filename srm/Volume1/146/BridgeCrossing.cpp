// BEGIN CUT HERE

// END CUT HERE
#line 5 "BridgeCrossing.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BridgeCrossing {
	int t[10], n;
	int ans[1 << 10][2];
	void update(int x, int y, int w, int s) {
		if (ans[x][s^1] == -1) ans[x][s^1] = ans[y][s] + w;
		else ans[x][s^1] = min(ans[x][s^1], ans[y][s] + w);
	}
	public:
	int minTime(vector <int> times) {
		n = times.size();
		memset(ans, 0xff, sizeof(ans));
		ans[0][0] = 0;
		for (int i = 0; i < n; i ++) t[i] = times[i];
		sort(t, t+n);
		int total = 2 * (1<<n);
		while (total --) {
			for (int j = 0; j < (1<<n); j++) for (int i = 0; i < 2; i ++) if (ans[j][i] != -1) {
				for (int k = 0; k < n; k ++) {
					if (i == 1 && (j & (1<<k))){
						update(j-(1<<k), j, t[k], i);
					} else if (i == 0 && !(j & (1<<k))){
						update(j+(1<<k), j, t[k], i);
					}
				}
				for (int k = 0; k < n; k ++) {
					for (int s = k + 1; s < n; s++) {
						if (i == 1 && ((j & (1<<k)) && (j & (1<<s)))) update(j-(1<<k)-(1<<s), j, t[s], i);
						else if (i == 0 && (!(j & (1<<k)) && !(j & (1<<s)))) update(j+(1<<k)+(1<<s), j, t[s], i);
					}
				}
			}
		}
		return ans[(1 << n) - 1][1];
	}
};
