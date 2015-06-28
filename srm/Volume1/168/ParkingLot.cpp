#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <queue>
#include <functional>
#include <numeric>
#include <cstring>
#include <memory>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cstdio>

using namespace std;

const int INF = 0x3fffffff;
const int maxn = 60;

const int ox[4] = {-1, 0, 0, 1};
const int oy[4] = {0, -1, 1, 0};

class ParkingLot {
	vector<pair<int, int> > car;
	vector<pair<int, int> > slot;
	priority_queue<pair<int, pair<int, int> > > q;
	int n, m;
	int dis[maxn][maxn];
	vector<int> calc(int x, int y, const vector<string> &b, int f) {
		queue<pair<int, int> > q;
		q.push(make_pair(x, y));
		memset(dis, 0xff, sizeof(dis));
		dis[x][y] = 0;
		while (!q.empty()) {
			int nx = q.front().first;
			int ny = q.front().second;
			q.pop();
			if (f && b[nx][ny] == 'A') continue;
			for (int i = 0; i < 4; i ++) {
				int tx = nx + ox[i];
				int ty = ny + oy[i];
				if (tx < 0 || ty < 0 || tx >= n || ty >= m) continue;
				if (b[tx][ty] == 'X' || b[tx][ty] == 'E' || dis[tx][ty] != -1) continue;
				if (f && b[tx][ty] == 'U') continue;
				dis[tx][ty] = dis[nx][ny] + 1;
				q.push(make_pair(tx, ty));
			}
		}
		vector<int> ans(slot.size());
		for (int i = 0; i < slot.size(); i ++) ans[i] = dis[slot[i].first][slot[i].second];
		return ans;
	}
public:
	int fastest(vector <string>);
};

int ParkingLot::fastest(vector <string> lot) {
	n = lot.size();
	m = lot[0].length();
	int s = 0, ex = 0, ey = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (lot[i][j] == 'A') slot.push_back(make_pair(i, j));
			else if (lot[i][j] == 'C') car.push_back(make_pair(i, j));
			else if (lot[i][j] == 'Y') {
				s = car.size();
				car.push_back(make_pair(i, j));
			} else if (lot[i][j] == 'E') {
				ex = i, ey = j;
			}
		}
	}
	vector<int> dist = calc(ex, ey, lot, 0);
	for (int i = 0; i < car.size(); i ++) {
		vector<int> dis = calc(car[i].first, car[i].second, lot, 1);
		for (int j = 0; j < dis.size(); j ++) if (dis[j] != -1) {
			q.push(make_pair(-dis[j], make_pair(-j, -i)));
		}
	}
	puts("!");
	vector<int> mkc(car.size());
	vector<int> mks(slot.size());
	int ans = INF;
	while (!q.empty()) {
		int x = -q.top().second.first;
		int y = -q.top().second.second;
		int z = -q.top().first;
		q.pop();
		if (mkc[y] || mks[x]) continue;
		if (y == s && dist[x] != -1) {
			ans = min(ans, dist[x] * 2 + z);
		} else {
			mkc[y] = 1;
			mks[x] = 1;
		}
	}
	return (ans == INF) ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!
