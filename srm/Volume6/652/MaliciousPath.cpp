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
#include <queue>
#include <ctime>

typedef long long ll;
const ll INF = 1LL << 60;

using namespace std;

class MaliciousPath {
	vector<list<pair<int, int> > > graph;
	vector<ll> bound, dist;
	int n;
	void dijkstra() {
		dist = vector<ll> (n, INF);
		priority_queue<pair<ll, int> > q;
		q.push(make_pair(0, n - 1));
		dist[n - 1] = 0;
		while (!q.empty()) {
			int v = q.top().second;
			ll d = - q.top().first;
			q.pop();
			if (dist[v] == d) {
				for (auto it: graph[v]) {
					int u = it.first;
					d = max(bound[u], dist[v] + it.second);
					if (dist[u] > d) {
						dist[u] = d;
						q.push(make_pair(-dist[u], u));
					}
				}
			}
		}
	} 
public:
	long long minPath(int, int, vector <int>, vector <int>, vector <int>);
};

long long MaliciousPath::minPath(int N, int K, vector <int> from, vector <int> to, vector <int> cost) {
	graph.resize(N);
	dist.resize(N);
	bound.resize(N);
	n = N;
	for (int i = 0; i < from.size(); i ++) {
		graph[to[i]].push_back(make_pair(from[i], cost[i]));
	}
	for (int i = 0; i <= K; i ++) {
		dijkstra();
		for (int j = 0; j < N; j ++) {
			for (auto it: graph[j]) {
				int u = it.first, w = it.second;
				bound[u] = max(bound[u], dist[j] + w);
			}
		}
	}
	return (dist[0] >= INF) ? -1 : dist[0];
}