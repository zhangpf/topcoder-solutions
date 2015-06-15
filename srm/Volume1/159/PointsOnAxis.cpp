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
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 1000010;

class PointsOnAxis {
	int calc(int x) {
		int ret = 1;
		while (ret * (ret - 1) < x + x) {
			ret ++;
		}
		return ret;
	}
	int n;
	int mk[maxn];
	int y[50], s[20], len ;
	int dfs(int now, int x, int f) {
		if (now >= n - 1) {
			int k, ok = 1;
			for (int j = 0; j < n - 1; j ++) {
				k = s[n - 1] - s[j];
				if (!mk[k]) {
					j --;
					ok = 0;
					while (j >= 0) mk[y[f + j]] ++, j --;
					break;
				} else {
					mk[k] --;
					y[f + j] = k;
				}
			}
			return ok;
		}
		for (int i = x; i <= (len - (n - 1 - now)); i ++) {
			int k, ok = 1;
			for (int j = 0; j < now; j ++) {
				k = i - s[j];
				if (!mk[k]) {
					j --;
					ok = 0;
					while (j >= 0) mk[y[f + j]] ++, j --;
					break;
				} else {
					mk[k] --;
					y[f + j] = k;
				}
			}
			if (!ok) continue;
			s[now] = i;
			if (dfs(now + 1, i + 1, now + f)) return 1;
			
			for (int j = 0; j < now; j ++) mk[y[j + f]] ++;
		}
		return 0;
	}
public:
	vector <int> findPoints(vector <int>);
};

vector <int> PointsOnAxis::findPoints(vector <int> d) {
	int N = d.size();
	n = calc(N);
	sort(d.begin(), d.end());
	memset(mk, 0, sizeof(mk));
	for (int i = 0; i < N; i ++) mk[d[i]]++;
	len = s[n - 1] = d[N - 1];
	s[0] = 0;		
	vector<int> ans;
	if (n >= 3) {
		s[1] = s[n - 1] - d[N - 2];
		y[0] = s[1] - s[0];
		if (mk[y[0]] == 0) return ans;
		mk[y[0]] --;
	}
	if(n <= 2 || dfs(2, s[1] + 1, 1)) {
		for (int i = 0; i < n; i ++) ans.push_back(s[i]);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
