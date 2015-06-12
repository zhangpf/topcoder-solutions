#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstring>
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

class QuipuReader {
	int pnt[maxn];
	int n, m;
	int getP(int x) {
		if (pnt[x] == -1) return -1;
		if (x == pnt[x]) return x;
		return pnt[x] = getP(pnt[x]);
	}
	void update(int l, int r) {
		for (int i = l; i < r; i ++) {
			if (pnt[i] == -1) pnt[i] = i;
			pnt[getP(i)] = getP(l);
		}
	}
public:
	vector <int> readKnots(vector <string>);
};

vector <int> QuipuReader::readKnots(vector <string> st) {
	vector<int> ans;
	n = st.size();
	m = st[0].length();
	memset(pnt, 0xff, sizeof(pnt));
	for (int i = 0; i < n; i ++) {
		int s = -1;
		for (int j = 0; j < m; j ++) {
			if (st[i][j] == 'X') {
				if (s == -1) s = j;
			}
			if (s != -1 && st[i][j] != 'X') {
				update(s, j);
				s = -1;
			} else if (s != -1 && j == m - 1) update(s, m);
		}
	}
	vector<pair<int, int> > di;
	for (int i = 0; i < m; ) {
		if (pnt[i] == -1) i ++;
		else {
			int b = i;
			do {
				i ++;
			} while (i < m && getP(i) == getP(i - 1));
			di.push_back(make_pair(b, i - b));
		}
	}
	for (int i = 0; i < n; i ++) {
		int ret = 0;
		for (int j = 0; j < di.size(); j++) {
			int now = di[j].first, cnt = 0;
			for (int k = 0; k < di[j].second; k ++) {
				if (st[i][now + k] == 'X') cnt ++;
			}
			ret = ret * 10 + cnt;
		}
		ans.push_back(ret);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
