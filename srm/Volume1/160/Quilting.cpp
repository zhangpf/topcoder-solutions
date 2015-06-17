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

class Quilting {
	int c[201][201];
public:
	string lastPatch(int, int, vector <string>);
};

const int ox[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
const int oy[8] = {0, -1, 0, 1, 1, -1, 1, -1};

string Quilting::lastPatch(int n, int m, vector <string> cl) {
	int nowx = 100, nowy = 100, k = cl.size(), cnt = 0, d = 0;
	memset(c, 0xff, sizeof(c));
	vector<int> ct(k);
	int f = 0;
	while (cnt < n * m) {
		map<int, int> t;
		for (int i = 0; i < 8; i ++) {
			int xf = nowx + ox[i];
			int yf = nowy + oy[i];
			if (c[xf][yf] != -1) t[c[xf][yf]] ++;
		}
		int ch = 0;
		for (int i = 0; i < k; i ++) {
			if (t[i] < t[ch] || (t[i] == t[ch] && ct[i] < ct[ch])) ch = i;
		}
		c[nowx][nowy] = ch;
		ct[ch] ++;
		int nd = (d + 1) % 4;
		if (c[nowx + ox[nd]][nowy + oy[nd]] == -1) {
			d = nd;
		}
		nowx = nowx + ox[d];
		nowy = nowy + oy[d];
		f = ch;
		cnt ++;
	}
	return cl[f];
}
//Powered by [KawigiEdit] 2.0!
