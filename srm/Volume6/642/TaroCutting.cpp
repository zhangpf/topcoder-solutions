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
#include <cstring>
#include <memory>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int MAXN = 500;
const int MAXM = 100000;
const int INF = 0x3fffffff;

using namespace std;

class TaroCutting {
	int c[MAXM], f[MAXM], w[MAXM], ev[MAXM], be[MAXM], nxt[MAXM];
	int value[MAXN], nbs[MAXN], pnt[MAXN], q1[MAXN], q2[MAXN];
	int d[MAXN], mk[MAXN], num;
	void init() {
		memset(nbs, 0xff, sizeof(nbs));
		num = 0;
	}
	void addEdge(int u, int v, int cc, int ww) {
		nxt[++num] = nbs[u]; nbs[u] = num; be[num] = num + 1;
		ev[num] = v; c[num] = cc; f[num] = 0; w[num] = ww;
		nxt[++num] = nbs[v]; nbs[v] = num; be[num] = num - 1;
		ev[num] = u; c[num] = 0; f[num] = 0; w[num] = -ww;
	}
	void minCost(int n, int s, int t, int &flow, int &cost) {
		memset(f, 0, sizeof(f));
		flow = 0; cost = 0;
		int t1, t2, u, v;
		do {
			memset(d, 0, sizeof(d));
			for (int i = 0; i < n; i ++) value[i] = INF;
			q1[1] = s; d[s] = INF; t1 = 1;  value[s] = 0;
			while (t1) {
				memset(mk, 0, sizeof(mk));
				for (int i = 1; i <= t1; i ++) q2[i] = q1[i];
				t2 = t1; t1 = 0; pnt[s] = -1; 
				for (int i = 1; i <= t2; i ++) {
					u = q2[i]; 
					for (int j = nbs[u]; j; j = nxt[j]) {
						v = ev[j];
						if (f[j] < c[j] && value[u] < INF && value[u] + w[j] < value[v]) {
							if (!mk[v]) { mk[v] = 1; q1[++t1] = v; }
							pnt[v] = j; 
							value[v] = value[u] + w[j];
							d[v] = min(d[u], c[j] - f[j]);
						}
					}
				}
			}
			if (value[t] == INF) break;
			flow += d[t]; cost += d[t] * value[t];
			for (int j = t, i = t; i != s; i = ev[be[j]]) {
				j = pnt[i];
				f[j] += d[t];
				f[be[j]] = - f[j];
			}
		} while (d[t] > 0);
	}
public:
	int getNumber(vector <int>, vector <int>, vector <int>, int);
};

int TaroCutting::getNumber(vector <int> h, vector <int> a, vector <int> d, int k) {
	init();
	int n = h.size(), m = d.size();
	int s = n + m + k, t = n + m + k + 1, none = n + m + k + 2;
	for (int i = 0; i < n; i ++) {
		addEdge(s, i, 1, 0);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < k; j ++) {
			addEdge(i, j + n, 1, (k - j - 1) * a[i]);
		}
		addEdge(i, none, 1, a[i] * k + h[i]);
	}
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < m; j ++) {
			addEdge(i + n, j + n + k, 1, d[j]);
		}
	}
	for (int i = 0; i < m; i ++) {
		addEdge(i + n + k, t, k, 0);
	}
	addEdge(none, t, n, 0);
	int f, c;
	minCost(n + m + k + 3, s, t, f, c);
	return c;
}
//Powered by [KawigiEdit] 2.0!
