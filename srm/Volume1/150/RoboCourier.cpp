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

using namespace std;
const int inf = 0x3fffffff;
const int maxn = 1010;

class RoboCourier {
	map<pair<int, int>, int> v;
	int ev[maxn][6];
	int mk[maxn][6];
	int ans[maxn][6], q1[maxn * 12], q2[maxn * 12];
	int hash(int x, int y) {
		return 6 * x + y;
	}
public:
	int timeToDeliver(vector <string>);
};

const int tx[6] = {1, 1, 0, -1, -1, 0};
const int ty[6] = {1, 0, -1, -1, 0, 1};

int RoboCourier::timeToDeliver(vector <string> paths) {
	string path = "";
	for (int i = 0; i < paths.size(); i++) path += paths[i];
	int nowx = 0, nowy = 0, nowf = 0;
	v[make_pair(0, 0)] = 0;
	int cnt = 1;
	memset(ev, 0xff, sizeof(ev));
	for (int i = 0; i < path.length(); i ++) {
		if (path[i] == 'L') nowf = (nowf + 5) % 6;
		else if (path[i] == 'R') nowf = (nowf + 1) % 6;
		else {
			int s = v[make_pair(nowx, nowy)];
			nowx += tx[nowf];
			nowy += ty[nowf];
			if (v.find(make_pair(nowx, nowy)) == v.end()) {
				v[make_pair(nowx, nowy)] = cnt ++;
			}
			int t = v[make_pair(nowx, nowy)];
			ev[s][nowf] = t;
			ev[t][(nowf + 3) % 6] = s;
		}
	}
	q1[1] = 0;
	for (int i = 0; i < cnt; i ++) {
		for (int j = 0; j < 6; j ++) ans[i][j] = inf;
	}
	memset(mk, 0, sizeof(mk));
	ans[0][0] = 0;
	int tail1 = 1, tail2 = 0, p = 0;
	while(p ++, tail1) {
		for (int i = 1; i <= tail1; i ++) q2[i] = q1[i];
		tail2 = tail1; tail1 = 0;
		for (int i = 1; i <= tail2; i ++) {
			int u = q2[i] / 6;
			int d = q2[i] % 6;
			for (int j = -1; j < 2; j ++) if (j != 0) {
				int nd = (j + d + 6) % 6;
				if (ans[u][nd] > ans[u][d] + 3) {
					ans[u][nd] = ans[u][d] + 3;
					if (mk[u][nd] != p) {
						q1[++tail1] = hash(u, nd);
						mk[u][nd] = p;
					}
				}
			}
			int len = 0, k = u;
			while (ev[k][d] != -1) {
				k = ev[k][d];
				len ++;
				int dis = (len >= 2 ? (len * 2 + 4) : len * 4);
				if (ans[k][d] > ans[u][d] + dis) {
					ans[k][d] = ans[u][d] + dis;
					if (mk[k][d] != p) {
						mk[k][d] = p;
						q1[++tail1] = hash(k, d);
					}
				}
			}
		}
	}
	int end = v[make_pair(nowx, nowy)];
	int ret = inf;
	for (int i = 0; i < 6; i ++) ret = min(ret, ans[end][i]);
	return ret;
}

//Powered by [KawigiEdit] 2.0!
