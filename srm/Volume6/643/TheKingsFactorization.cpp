#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAXN = 1000000;
class TheKingsFactorization {
	int mk[MAXN], prime[MAXN];
	vector<ll> calc(ll &x) {
		int num = 0;
		vector<ll> ans;
		printf("%lld\n", x);
		for(int i = 2; i < MAXN; i ++) {
			if (!mk[i]) {
				prime[num ++] = i;
				while (x % i == 0) {
					x /= i;
					ans.push_back(i);
				}
			}
			for (int j = 0; j < num && i * prime[j] < MAXN; ++j) {
				mk[i * prime[j]] = 1;
		        if(0 == i % prime[j]) break;
			}
		}
		return ans;
	}
public:
    vector<long long> getVector(long long re, vector<long long> p) {
		vector<ll> ans = calc(re);
		if (re != 1) {
			if (p.size() && p[p.size() - 1] >= MAXN) {
				ll k = p[p.size() - 1];
				re /= k;
				if (re == 1) ans.push_back(k);
				else if (k > re) ans.push_back(re), ans.push_back(k);
				else ans.push_back(k), ans.push_back(re);
			} else ans.push_back(re);
		}
		return ans;
    }
};
