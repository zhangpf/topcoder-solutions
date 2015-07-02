#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <queue>
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

class BuildingTowers {
	ll calc(ll left, ll right, ll k, int dis) {
		ll low = max(left, right) + 1, high = 1LL << 60;
		while (low < high) {
			ll mid = (low + high) / 2;
			if (((mid - left + k - 1) / k) + ((mid - right + k - 1) / k) <= dis) low = mid + 1;
			else high = mid;
		}
		return low - 1;
	}
public:
	long long maxHeight(int, int, vector <int>, vector <int>);
};

long long BuildingTowers::maxHeight(int N, int K, vector <int> x, vector <int> t) {
	int n = x.size();
	vector<list<pair<int, ll> > > g;
	g.resize(n + 2);
	for (int i = 0; i < n; i ++) {
		if (i == 0) {
			g[n].push_back(make_pair(0, (ll)(x[i] - 1) * K));
			g[0].push_back(make_pair(n, (ll)(x[i] - 1) * K));
		}
		if (i < n - 1) {
			g[i].push_back(make_pair(i + 1, (ll)(x[i + 1] - x[i]) * K));
			g[i + 1].push_back(make_pair(i, (ll)(x[i + 1] - x[i]) * K));
		}
		else if (i == n - 1) {
			g[i].push_back(make_pair(n + 1, (ll)(N - x[i]) * K));
			g[n + 1].push_back(make_pair(i, (ll)(N - x[i]) * K));
		}
	}
	for (int i = 0; i < n; i ++) {
		g[n].push_back(make_pair(i, (ll)t[i]));
		g[n].push_back(make_pair(i, (ll)(x[i] - 1) * K));
	}
	g[n].push_back(make_pair(n + 1, (ll)(N - 1) * K));
	priority_queue<pair<ll, int> > p;
	vector<ll> dis(n + 2, 1LL << 60);
	dis[n] = 0;
	
	p.push(make_pair(0, n));
	while (!p.empty()) {
		ll d = -p.top().first;
		int u = p.top().second;
		p.pop();
		if (dis[u] == d) {
			for (auto it: g[u]) {
				int v = it.first;
				if (dis[v] > d + it.second) {
					dis[v] = d + it.second;
					p.push(make_pair(-dis[v], v));
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n + 2; i ++) {
		ans = max(ans, dis[i]);
		if (i < n - 1) ans = max(ans, calc(dis[i], dis[i + 1], K, x[i + 1] - x[i]));
		if (i == n && n) ans = max(ans, calc(dis[n], dis[0], K, x[0] - 1));
		if (i == n + 1 && n) ans = max(ans, calc(dis[n - 1], dis[i], K, N - x[n - 1]));
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
