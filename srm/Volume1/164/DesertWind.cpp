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
#include <queue>

using namespace std;
const int tx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
const int ty[8] = {-1, 1, 0, 0, -1, -1, 1, 1};


class DesertWind {
	vector<string> c;
	int sx, sy;
	int n, m;
	int ans[60][60];
	int calc() {
		memset(ans, 0xff, sizeof(ans));
		for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) {
			if (c[i][j] == '*') ans[i][j] = 0;
		}
		int now = 0, last = -1;
		while (now <= last + 5 && ans[sx][sy] == -1) {
			now ++;
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) if (ans[i][j] == -1) {
					int cnt = 0;
					for (int k = 0; k < 8; k ++) {
						int ox = i + tx[k];
						int oy = j + ty[k];
						if (ox < 0 || oy < 0 || ox >= n || oy >= m || c[ox][oy] == 'X'
							|| ans[ox][oy] == -1) continue;
						if (ans[ox][oy] <= now - 3) {
							ans[i][j] = now;
							last = now;
						}
						if (ans[ox][oy] < now) cnt ++;
					}
					if (cnt >= 2) {
						ans[i][j] = now;
						last = now;
					}
				}
			}
		}
		return ans[sx][sy];
	}
public:
	int daysNeeded(vector <string>);
};

int DesertWind::daysNeeded(vector <string> theMap) {
	n = theMap.size();
	m = theMap[0].length();
	c = theMap;
	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) {
		if (c[i][j] == '@') {
			sx = i; sy = j;
		}
	}
	return calc();
}
//Powered by [KawigiEdit] 2.0!
