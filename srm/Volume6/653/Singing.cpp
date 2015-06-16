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

const int maxm = 10010;
const int maxn = 2010;
const int inf = 0x3fffffff;
using namespace std;

class Singing {
	int num;
	int c[maxm], f[maxm], ev[maxm], be[maxm], next[maxm];
	int nbs[maxn], pnt[maxn], open[maxn], d[maxn], mk[maxn];
	void addEdge(int u, int v, int cc) {
		next[++num] = nbs[u]; nbs[u] = num; be[num] = num + 1;
		ev[num] = v; c[num] = cc; f[num] = 0;
		next[++num] = nbs[v]; nbs[v] = num; be[num] = num - 1;
		ev[num] = u; c[num] = 0; f[num] = 0;
	}
	int maxFlow(int s, int t) {
		int cur, tail, j, u, v, flow = 0;
		do {
			memset(mk, 0, sizeof(mk));
			memset(d, 0, sizeof(d));
			open[0] = s; mk[s] = 1; d[s] = inf;
			for (pnt[s] = cur = tail = 0; cur <= tail && !mk[t]; cur ++) {
				for (u = open[cur], j = nbs[u]; j; j = next[j]) {
					v = ev[j];
					if (!mk[v] && f[j] < c[j]) {
						mk[v] = 1; open[++ tail] = v; pnt[v] = j;
						d[v] = min(d[u], c[j] - f[j]); 
					}
				}
			}
			if (!mk[t]) break;	flow += d[t];
			for (u = t; u != s; u = ev[be[j]]) {
				j = pnt[u]; f[j] += d[t]; f[be[j]] = -f[j];
			}
		} while(d[t] > 0); return flow;
	}
public:
	int solve(int, int, int, vector <int>);
};

int Singing::solve(int N, int low, int high, vector <int> pitch) {
	int s = N + 1, t = N + 2;
	memset(nbs, 0, sizeof(nbs));
	num = 0;
	for (int i = 1; i < low; i ++) addEdge(s, i, inf);
	for (int i = high + 1; i <= N; i ++) addEdge(i, t, inf);
	for (int i = 1; i < pitch.size(); i ++) {
		addEdge(pitch[i], pitch[i - 1], 1);
		addEdge(pitch[i - 1], pitch[i], 1);
	}
	return maxFlow(s, t);
}
//Powered by [KawigiEdit] 2.0!
