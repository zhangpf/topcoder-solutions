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
#include <cstring>
#include <memory>

using namespace std;
const int maxm = 30010;
const int INF = 0x3fffffff;
const int maxn = 210;

class DancingForever {
	int c[maxm], f[maxm], ev[maxm], be[maxm], nxt[maxm];
	int nbs[maxn], pnt[maxn], open[maxn], d[maxn], mk[maxn];
	int num;
	void addEdge(int u, int v, int cc) {
		nxt[++num] = nbs[u]; nbs[u] = num; be[num] = num + 1;
		ev[num] = v; c[num] = cc; f[num] = 0;
		nxt[++num] = nbs[v]; nbs[v] = num; be[num] = num - 1;
		ev[num] = u; c[num] = 0; f[num] = 0;
	}
	int maxFlow(int s, int t) {
		int cur, tail, j, u, v, flow = 0;
		do {
			memset(mk, 0, sizeof(mk));
			memset(d, 0, sizeof(d));
			open[0] = s; mk[s] = 1; d[s] = INF;
			for (pnt[s] = cur = tail = 0; cur <= tail && !mk[t]; cur ++) {
				for (u = open[cur], j = nbs[u]; j; j = nxt[j]) {
					v = ev[j];
					if (!mk[v] && f[j] < c[j]) {
						mk[v] = 1;
						open[++tail] = v;
						pnt[v] = j;
						d[v] = min(d[u], c[j] - f[j]);
					}
				}
			}
			if (!mk[t]) break;
			flow += d[t];
			for (u = t; u != s; u = ev[be[j]]) {
				j = pnt[u];
				f[j] += d[t];
				f[be[j]] = -f[j];
			}
		} while (d[t] > 0); return flow;
	}
	int n;
	//int mkg[maxn], mkb[maxn];
	void dfs (int x) {
		printf("%d\n", x);
		mk[x] = 1;
		for (int i = nbs[x]; i; i = nxt[i]) {
			if (f[i] < c[i] && mk[ev[i]] == 0) 
				dfs(ev[i]);
		}
	}
public:
	vector <int> getStablePairs(string);
};


vector <int> DancingForever::getStablePairs(string x) {
	n = int(sqrt(x.length() + 0.1));
	memset(nbs, num = 0, sizeof(nbs));
	int s = 2 * n, t = 2 * n + 1;
	for (int i = 0; i < n; i ++) {
		addEdge(s, i, 1);
		addEdge(i + n, t, 1);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) if (x[i * n  + j] == 'Y'){
			addEdge(i, j + n, INF);
		}
	}
	int maxF = maxFlow(s, t);
	vector<int> ans;
	memset(mk, 0, sizeof(mk));
	if (maxF == n) {
		for (int i = 0; i < n; i ++) mk[i] = 1;
	} else dfs(s);
	for (int i = 0; i < n; i ++) if(mk[i]) {
		for (int j = nbs[i]; j; j = nxt[j]) {
			if (ev[j] < 2 * n && f[j] == 1) {
				ans.push_back(i);
				ans.push_back(ev[j] - n);
			}
		}
	}	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
