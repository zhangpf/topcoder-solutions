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
const int MOD = 1000000007;
typedef long long ll;

class KitayutaMart {
	ll powmod(int x, int y, int m) {
		ll ans = 1, now = x;
		while (y) {
			if (y & 1) ans = ans * now % m;
			now = now * now % m;
			y >>= 1;
		}
		return ans % m;
	}
	int check(int x, int y, int n) {
		x ++;
		ll ans = 0;
		int now = 1, sum = 0;
		while (sum < y) {
			ans += (ll)x * (now - sum);
			if (ans >= n) return 1;
			sum = now;
			if (now + now > y) now = y;
			else now <<= 1;
			x --;
		}
		return 0;
	}
	int check2(int x, int y, int z, int n) {
		ll ans = 0;
		y ++;
		int now = x, sum, f = y;
		while (now) {
			ans += (ll)f * (now - (now >> 1));
			if (ans >= n) return 1;
			now >>= 1;
			f ++;
		}
		f = y, now = x, sum = x;
		while (f && sum < z) {
			ans += (ll)f * (now - sum);
			if (ans >= n) return 1;
			sum = now;
			if (now + now >= z) now = z;
			else now <<= 1;
			f --;
		}
		return 0;
	}
	int calc(int high, int s, int K, int N) {
		int low = 1;
		while (low < high) {
			int mid = (low + high) >> 1;
			if (check2(mid, s, K, N)) high = mid;
			else low = mid + 1;
		}	
		return low;
	}
public:
	int lastPrice(int, int);
};

int KitayutaMart::lastPrice(int N, int K) {
	int low = 0, high = N;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid, K, N)) high = mid;
		else low = mid + 1;
	}
	int k = low, s, f = (int)(log(K) / log(2) + 1e-8), ans;
	if (k <= f) {
		low = 1, high = 1 << f, s = 0;
		ans = calc(high, s, K, N);
	} else {
		low = 1, high = K, s = (k - f); 
		int ans1 = calc(K, s, K, N);
		int ans2 = (s < 1) ? 0x3fffffff : calc(2 * K, s - 1, K, N);
		if (ans2 <= K && ans2 < 2 * ans1) {
			ans = ans2;
			s --;
		} else ans = ans1;
	}
	return (int)(powmod(2, s, MOD) * ans % MOD);
}

//Powered by [KawigiEdit] 2.0!
