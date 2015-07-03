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

using namespace std;

class Cubism {
	string cube[4][4];
	int ok(int x) { return x >= 0 && x < 4; }
	int hash(int x, int y, int z, int u, int v, int w, char c) {
		vector<int> ans(4);
		for (int i = 0; i < 4; i ++) {
			int nx = x + i * u;
			int ny = y + i * v;
			int nz = z + i * w;
			if (cube[nx][ny][nz] != c) return -1;
			ans[i] = nx * 16 + ny * 4 + nz;
		}
		sort(ans.begin(), ans.end());
		int ret = 0;
		for (int i = 0; i < 4; i ++) ret = (ret * 64 + ans[i]);
		return ret;
	}
public:
	int lines(vector <string>, string);
};

int Cubism::lines(vector <string> s, string color) {
	char c = (color[0] == 'b') ? 'B' : 'W';
	for (int i = 0; i < 4; i ++) 
		for (int j = 0; j < 4; j ++)  
			cube[i][j] = s[i].substr(j << 2, 4);
	
	set<int> ans;
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < 4; j ++) {
			for (int k = 0; k < 4; k ++) {
				for (int u = -1; u < 2; u ++) {
					for (int v = -1; v < 2; v ++) {
						for (int w = -1; w < 2; w ++) {
							if (w == 0 && v == 0 && u == 0) continue;
							if (!ok(3 * u + i) || !ok(3 * v + j) || !ok(3 * w + k)) continue;
							int h = hash(i, j, k, u, v, w, c);
							if (h == -1) continue;
							ans.insert(h);
						}
					}
				}
			}
		}
	}
	return ans.size();
}
//Powered by [KawigiEdit] 2.0!
