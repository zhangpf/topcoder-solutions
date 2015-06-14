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

using namespace std;
const int maxn = 30;
const int inf = 0x3fffffff;

class PickTeam {
	string name[maxn];
	int t[maxn][maxn];
public:
	vector <string> pickPeople(int, vector <string>);
};

vector <string> PickTeam::pickPeople(int S, vector <string> p) {
	int n = p.size();
	for (int i = 0; i < n; i ++) {
		stringstream sin(p[i]);
		sin >> name[i];
		for (int j = 0; j < n; j ++) sin >> t[i][j];
	}
	int ch = -1, ret = -inf;
	for (int i = 0; i < (1 << n); i ++) {
		int s = i, cnt = 0;
		while (s) {
			s -= s & (-s);
			cnt ++;
		}
		if (cnt != S) continue;
		int ans = 0;
		for (int j = 0; j < n; j ++) if (i & (1 << j)) {
			for (int k = j + 1; k < n; k ++) if (i & (1 << k)) {
				ans += t[j][k];
			}
		}
		if (ans > ret) {
			ret = ans; ch = i;
		}
	}
	vector<string> ans;
	for (int i = 0; i < n; i ++) if (ch & (1 << i)) {
		ans.push_back(name[i]);
	}
	sort(ans.begin(), ans.end());
	return ans;
}
//Powered by [KawigiEdit] 2.0!
