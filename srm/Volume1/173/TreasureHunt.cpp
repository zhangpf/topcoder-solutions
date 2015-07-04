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

const int INF = 0x3fffffff;
using namespace std;

const int ox[4] = {-1, 1, 0, 0};
const int oy[4] = {0, 0, 1, -1};

class TreasureHunt {
	int n, m;
	int isBeach(vector<string> &b, int x, int y) {
		for (int i = 0; i < 4; i ++) {
			int tx = x + ox[i];
			int ty = y + oy[i];
			if (tx < 0 || ty < 0 || tx >= n || ty >= m || b[tx][ty] == '.') return 1;
		}
		return 0;
	}
public:
	vector <int> findTreasure(vector <string>, vector <string>);
};

vector <int> TreasureHunt::findTreasure(vector <string> b, vector <string> ins) {
	n = b.size(), m = b[0].length();
	int ansl = INF, ansx, ansy, tx = 0, ty = 0;
	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) if (b[i][j] == 'X') {
		tx = i, ty = j;
	}
	cout << tx << " " << ty << endl;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (b[i][j] != '.') {
			if (!isBeach(b, i, j)) continue;
			int sx = i, sy = j;
			char di; int d, len;
			int ok = 1;
			for (int k = 0; ok && k < ins.size(); k ++) {
				stringstream sin(ins[k]);
				sin >> di >> len;
				if (di == 'N') d = 0;
				else if (di == 'S') d = 1;
				else if (di == 'E') d = 2;
				else d = 3;
				for (int u = 0; ok && u <= len; u ++) {
					if (sx >= 0 && sy >= 0 && sx < n && sy < m && b[sx][sy] != '.') ok = 1;
					else ok = 0;
					if (u == len) break;
					sx = sx + ox[d]; sy = sy + oy[d];
				}
			}
			if (!ok) continue;
			int dis = (sx - tx) * (sx - tx) + (sy - ty) * (sy - ty);
			if (ansl > dis) {
				ansl = dis;
				ansx = sy, ansy = sx;
			}
		}
	}
	vector<int> ans;
	if (ansl < INF) {
		ans.push_back(ansx);
		ans.push_back(ansy);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
