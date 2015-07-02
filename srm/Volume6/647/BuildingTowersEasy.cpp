#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <queue>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

class BuildingTowersEasy {
	void update(int x, int y, priority_queue<pair<int, int> > &q, vector<int> &dis) {
		if (dis[x] <= y) return;
		q.push(make_pair(-y, x));
		dis[x] = y;
	}
public:
	int maxHeight(int, vector <int>, vector <int>);
};

int BuildingTowersEasy::maxHeight(int N, vector <int> x, vector <int> t) {
	vector<pair<int, int> > y;
	for (int i = 0; i < x.size(); i ++) y.push_back(make_pair(x[i], t[i]));
	y.push_back(make_pair(1, 0));
	y.push_back(make_pair(N , N - 1));
	sort(y.begin(), y.end());
	int n = y.size();
	vector<int> dis(n, 1<<29);
	
	priority_queue<pair<int, int> > q;
	dis[0] = 0;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int u = q.top().second;
		int d = -q.top().first;
		assert(u < n);
		q.pop();
		if (dis[u] == d) {
			for (int i = 0; i < n; i ++) {
				if (u == 0) update(i, y[i].second, q, dis);
				update(i, d + abs(y[i].first - y[u].first), q, dis);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		ans = max(ans, dis[i - 1]);
		ans = max(ans, dis[i]);
		ans = max(ans, (dis[i] + dis[i - 1] + y[i].first - y[i - 1].first) / 2);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
