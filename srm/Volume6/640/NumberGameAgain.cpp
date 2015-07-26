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

class NumberGameAgain {
public:
	long long solve(int, vector<long long>);
};

long long NumberGameAgain::solve(int k, vector<long long> t) {
	ll ans = 0;
	for (int i = 0; i < t.size(); i ++) {
		ll now = t[i];
		int ok = 1;
		do {
			now >>= 1;
			for (int j = 0; j < t.size(); j ++) if (now == t[j]) ok = 0;
		} while (now != 1 && ok);
		if (!ok) continue;
		int p = 0;
		while ((t[i] << p) < (1LL << k)) p ++;
		ans += (1LL << p) - 1;
	}
	return (1LL << k) - 2 - ans;
}
//Powered by [KawigiEdit] 2.0!
