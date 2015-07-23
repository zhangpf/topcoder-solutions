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
#include <cstring>
#include <memory>
#include <cstdlib>
#include <ctime>
typedef long long ll;

using namespace std;

class CheeseRolling {
	ll ans[1 << 16][16];
	vector<string> w;
	int n;
	vector<int> getS(int x) {
		vector<int> ret;
		for (int i = 0; i < n; i ++) if (x & (1 << i)) ret.push_back(i);
		return ret;
	}
	vector<int> combine(int x, int y) {
		vector<int> h = getS(x);
		int sz = h.size();
		vector<int> ret;
		for (int i = 0; i < (1 << sz); i ++) {
			int ans = 0, cnt = 0;
			for (int j = 0; j < sz; j ++) if ((1 << j) & i) {
				cnt ++;
				ans |= (1 << h[j]);
			}
			if (cnt == y) ret.push_back(ans);
		}
		return ret;
	}
	
	ll calc(int x, int y) {
		if (ans[x][y] != -1) return ans[x][y];
		vector<int> f = getS(x);
		int sz = f.size();
		if (sz == 2) {
			int z = (f[0] == y) ? f[1] : f[0];
			if (w[z][y] == 'Y') return ans[x][y] = 0;
			return ans[x][y] = 2;
		} 
		ans[x][y] = 0;
		for (int i = 0; i < sz; i ++) if (w[y][f[i]] == 'Y') {
			vector<int> h = combine(x & ~(1 << y) & ~(1 << f[i]), sz / 2 - 1);
			for (int it: h) {
				ans[x][y] += calc(it | (1 << f[i]), f[i]) * calc(x & ~it & ~(1 << f[i]), y) * 2;
			}
		}
		return ans[x][y];
	}
public:
	vector<ll> waysToWin(vector <string>);
};

vector<ll> CheeseRolling::waysToWin(vector <string> W) {
	n = W.size();
	memset(ans, 0xff, sizeof(ans));
	w = W;
	vector<ll> ans(n);
	for (int i = 0; i < n; i ++) {
		ans[i] = calc((1 << n) - 1, i);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
