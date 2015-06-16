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
#include <memory>
#include <cstring>
#include <ctime>

using namespace std;
const int MOD = 1000000007;
const int maxn = 10010;
const int inf = 0x3fffffff;

class PolynomialGCD {
	int n;
	int prime[maxn], len;
	void init() {
		len = 0;
		for (int i = 2; i < maxn; i++) {
			int mk = 0;
			for (int j = 0; !mk && prime[j] * prime[j] <= i && j < len; j++) if(i % prime[j] == 0) {
				mk = 1;
			}
			if (!mk) prime[len ++] = i;
		}
	}
	int calc(string s, int p) {
		int minv = inf, len = s.size();
		if (len < p) {
			return 0;
		}
		for (int i = 0; i < p; i ++) {
			string r = "";
			int total = 0;
			for (int j = i; j < len; j += p) {
				total += s[j] - '0';
				r += s[j];
			}
			minv = min(minv, calc(r, p) + total);
		}
		return minv;
	}
public:
	int gcd(string);
};

int PolynomialGCD::gcd(string s) {
	n = s.size();
	init();
	int ans = 1;
	for (int i = 0; i < len; i++) {
		for (int j = calc(s, prime[i]); j >= 1; j --) {			
			ans = ((long long)ans * prime[i]) % MOD;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!