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
const int maxn = 40;

class BrickByBrick {
	int c[maxn][maxn][4];
	int mk[maxn][maxn][4];
	void paint(int x, int y, int color) {
		c[x + x][y + y + 1][2] = color;
		c[x + x + 2][y + y + 1][0] = color;
		c[x + x + 1][y + y][3] = color;
		c[x + x + 1][y + y + 2][1] = color; 
	}
public:
	int timeToClear(vector <string>);
};

int BrickByBrick::timeToClear(vector <string> map) {
	memset(c, 0, sizeof(c));
	int cnt = 0;
	int n = map.size(), m = map[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (map[i][j] == '#') {
				paint(i, j, -1);
			} else if (map[i][j] == 'B') {
				paint(i, j, 1);
				cnt ++;
			}
		}
	}
	int x = 0, y = 1, dx = 1, dy = 1, ans = 0;
	memset(mk, 0xff, sizeof(mk));
	while (cnt) {
		int s = (dx == 1) * 2 + (dy == 1);
		ans ++;
		if (mk[x][y][s] == cnt) {
			ans = -1;
			break;
		} else mk[x][y][s] = cnt;
		x = x + dx;
		y = y + dy;
		if (x == 0) dx = 1;
		else if (y == 0) dy = 1;
		else if (y == 2 * m) dy = -1;
		else if (x == 2 * n) dx = -1;
		else if (dx == 1 && dy == 1 && c[x][y][3]) {
			dx = 1; dy = -1;
			if (c[x][y][3] == 1) {
				paint(x / 2, y / 2, 0);
				cnt --;
			}
		} else if (dx == 1 && dy == 1 && c[x][y][2]) {
			dx = -1; dy = 1;
			if (c[x][y][2] == 1) {
				paint(x / 2, y / 2, 0);
				cnt --;
			}
		} else if (dx == -1 && dy == 1 && c[x][y][3]) {
			dx = -1; dy = -1;
			if (c[x][y][3] == 1) {
				paint(x / 2, y / 2, 0);
				cnt --;
			}
		} else if (dx == -1 && dy == 1 && c[x][y][0]) {
			dx = 1; dy = 1;
			if (c[x][y][0] == 1) {
				paint((x / 2) - 1, (y / 2) , 0);
				cnt --;
			}
		} else if (dx == 1 && dy == -1 && c[x][y][1]) {
			dx = 1; dy = 1;
			if (c[x][y][1] == 1) {
				paint(x / 2, (y / 2) - 1, 0);
				cnt --;
			}
		} else if (dx == 1 && dy == -1 && c[x][y][2]) {
			dx = -1; dy = -1;
			if (c[x][y][2] == 1) {
				paint(x / 2, y / 2, 0);
				cnt --;
			}
		} else if (dx == -1 && dy == -1 && c[x][y][0]) {
			dx = 1; dy = -1;
			if (c[x][y][0] == 1) {
				paint((x / 2) - 1, y / 2, 0);
				cnt --;
			}
		} else if (dx == -1 && dy == -1 && c[x][y][1]) {
			dx = -1; dy = 1;
			if (c[x][y][1] == 1) {
				paint(x / 2, (y / 2) - 1, 0);
				cnt --;
			}
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
