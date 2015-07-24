#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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
typedef long long ll;
using namespace std;

class TallShoes {
	vector<list<pair<int, int> > > g;
	int n;
	ll calc(int x) {
		priority_queue<pair<ll, int> > q;
		vector<ll> d(n);
		for (int i = 0; i < n; i ++) d[i] = 1LL << 62;
		d[0] = 0;
		q.push(make_pair(0, 0));
		while (!q.empty()) {
			ll dis = -q.top().first;
			int u = q.top().second;
			q.pop();
			if (dis != d[u]) continue;
			if (u == n - 1) break;
			for (auto it: g[u]) {
				int v = it.first;
				int w = it.second;
				ll newV = dis + ((w >= x) ? 0 : (ll)(w - x) * (w - x)); 
				if (newV < d[v]) {
					d[v] = newV;
					q.push(make_pair(-newV, v));
				}
			}
		}
		return d[n - 1];
	}
public:
	int maxHeight(int, vector <int>, vector <int>, vector <int>, long long);
};

int TallShoes::maxHeight(int N, vector <int> X, vector <int> Y, vector <int> h, long long B) {
	n = N;
	g.resize(n);
	for (int i = 0; i < X.size(); i ++) {
		g[X[i]].push_back(make_pair(Y[i], h[i]));
		g[Y[i]].push_back(make_pair(X[i], h[i]));
	}
	ll low = 1, high = 1e8;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (calc(mid) > B) high = mid;
		else low = mid + 1;
	}
	return low - 1;
}
//Powered by [KawigiEdit] 2.0!
