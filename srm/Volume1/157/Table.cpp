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
#include <cassert>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory>
#include <cstring>
#include <ctime>

using namespace std;
const int maxn = 60;

class Table {
	char b[maxn][maxn];
	int n, m;
public:
	vector <string> layout(vector <string>);
};

vector <string> Table::layout(vector <string> tbl) {
	n = tbl.size();
	m = 1;
	memset(b, 0, sizeof(b));
	for (int i = 0; i < n; i ++) {
		int now = 0;
		stringstream sin(tbl[i]);
		int c, r;
		char color, tmp;
		while (sin >> tmp >> c >> tmp >> r >> tmp >> color >> tmp) {
			while (b[i][now]) now ++;
			for (int j = 0; j < r; j ++) {
				for (int k = 0; k < c; k ++) {
					assert(b[i + j][now + k] == 0);
					b[i + j][now + k] = color;
				}
			}
			now += c;
			m = max(now, m);
		}
	}
	vector<string> ans;
	for (int i = 0; i < n; i ++) {
		string s(b[i]);
		ans.push_back(s);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
