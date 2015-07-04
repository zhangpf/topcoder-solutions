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

class Centipede {
	vector<pair<pair<int, int>, int> > init() {
		vector<pair<pair<int, int>, int> > st(10);
		for (int i = 0; i < 10; i ++) {
			st[i].second = 1; 
			st[i].first.first = 0;
			st[i].first.second = i + 1;
		}
		return st;
	}
public:
	vector <string> simulate(vector <string>, int);
};

vector <string> Centipede::simulate(vector <string> b, int t) {
	int now = 0, n = b.size();
	vector<pair<pair<int, int>, int> > st = init();
	while (now < t) {
		vector<pair<pair<int, int>, int> > newSt;
		for (int i = 0; i < st.size(); i ++) {
			int d = st[i].second;
			int x = st[i].first.first;
			int y = st[i].first.second;
			if (b[x][d + y] == '#') {
				if (x + 1 >= n) continue;
				if (b[x + 1][y] == ' ') x ++;
				d = -d;
			} else y += d;
			newSt.push_back(make_pair(make_pair(x, y), d));
		}
		st = newSt;
		now ++;
		if (st.size() == 0) {
			st = init();
			t = t % now + now;
		}
	}
	for (int i = 0; i < st.size(); i ++) 
		b[st[i].first.first][st[i].first.second] = 'x';
	return b;
}

//Powered by [KawigiEdit] 2.0!
