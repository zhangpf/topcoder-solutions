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
typedef long long ll;
using namespace std;
const int MOD = 1000000007;

class ChangingChange {
public:
	vector <int> countWays(vector <int>, vector <int>, vector <int>);
};

ll mod(ll x, ll m) { return (x % m + m) % m; }

void ext_gcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (b == 0) {
		d = a; 
		x = 1; 
		y = 0;
		return;
	} 
	ext_gcd(b, a % b, d, y, x);
	y -= x * (a / b);
}

ll inv(ll a, ll m) {
	ll d, x, y;
	ext_gcd(a, m, d, x, y);
	if (d == 1) return mod(x, m);
	return -1;
}

vector <int> ChangingChange::countWays(vector <int> w, vector <int> v, vector <int> c) {
	int n = v.size();
	int d = w.size() - 1;
	vector<int> ans(n);
	for (int i = 0; i < n; i ++) {
		ll ret = 0, hh = 1;
		int now = 1, cnt = 0;
		for (int j = d; j >= 0; j -= v[i]) {
			ret += hh * w[j] * now;
			hh = hh * (cnt + c[i]) % MOD;
			hh = hh * inv(cnt + 1, MOD) % MOD;
			now *= -1;
			cnt ++;
			ret %= MOD;
		}
		ans[i] = mod(ret, MOD);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
