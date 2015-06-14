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
#include <memory>
#include <cstring>q
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int inf = 0x3fffffff;
using namespace std;

class SmartElevator {
	int mk[10], st[10];
	int s[10], t[10], a[10];
	int ans, n;
	void dfs(int d, int now, int f) {
		if (d == n + n) {
			ans = min(ans, now);
			return;
		}
		for (int i = 0; i < n; i ++) if (!mk[i] && !st[i]) {
			mk[i] = 1;
			st[i] = 1;
			dfs(d + 1, max(a[i], now + abs(f - s[i])), s[i]);
			st[i] = 0;
			mk[i] = 0;
		}
		for (int i = 0; i < n; i ++) if (!mk[i + n] && st[i] == 1) {
			mk[i + n] = 1;
			st[i] = 2;
			dfs(d + 1, max(now + abs(f - t[i]), a[i]), t[i]);
			st[i] = 1;
			mk[i + n] = 0;
		}
	}
public:
	int timeWaiting(vector <int>, vector <int>, vector <int>);
};

int SmartElevator::timeWaiting(vector <int> A, vector <int> S, vector <int> T) {
	ans = inf;
	memset(mk, 0, sizeof(mk));
	memset(st, 0, sizeof(st));
	n = A.size();
	for (int i = 0; i < n; i ++) a[i] = A[i];
	for (int i = 0; i < n; i ++) s[i] = S[i];
	for (int i = 0; i < n; i ++) t[i] = T[i];
	dfs(0, 0, 1);
	return ans;
}
//Powered by [KawigiEdit] 2.0!
