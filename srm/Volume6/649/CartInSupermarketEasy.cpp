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
const int INF = 0x3fffffff;

using namespace std;

class CartInSupermarketEasy {
	int checkme(int x, int y) {
		if (y < 30 && x > (1 << (y - 1))) return INF;
		int low = 0, high = x - 1;
		if (y <= 30) high = min(1 << y, high);
		while (low < high) {
			int mid = (low + high) >> 1;
			int now = 0;
			while (mid + 1 >= (1 << now)) now ++;
			now --;
			int f = (mid + 1 - (1 << now));
			long long sum = (long long)f * 2 * (y - now - 1) + (long long)(mid + 1 - f * 2) * (y - now);
			if (sum >= x) high = mid;
			else low = mid + 1;
		}
		return low;
	}
	int check(int t, int n, int k) {
		return checkme(n, t) <= k;
	}
public:
	int calc(int, int);
};

int CartInSupermarketEasy::calc(int N, int K) {
	int low = 1, high = N;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid, N, K)) high = mid;
		else low = mid + 1;
	}
	return low;
}

//Powered by [KawigiEdit] 2.0!
