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
const int M = 1000000007;

class ColorfulLineGraphsDiv2 {
	ll calc(ll x, ll y, int z) {
		ll ret = 1;
		while (y) {
			if (y & 1) ret = ret * x % z;
			x = x * x % z;
			y >>= 1;
		}
		return ret;
	}
public:
	int countWays(int, int);
};

int ColorfulLineGraphsDiv2::countWays(int N, int K) {
	long long ans = 1;
	for (int i = 0; i < M && i <= N; i ++) {
		ll cnt = (N - i) / M + 1;
		ans = ans * calc(((K - 1) * i + 1) % M, cnt, M) % M;
	}
	return (int)ans;
}

//Powered by [KawigiEdit] 2.0!
