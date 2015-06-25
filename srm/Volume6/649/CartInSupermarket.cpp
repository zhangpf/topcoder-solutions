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
const int INF = 0x3fffffff;

class CartInSupermarket {
	vector<int> a;
	int b;
	int calc(int x, int y) {
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
	int check(int x) {
		int sum = 0;
		for (int i = 0; i < a.size(); i ++) {
			sum += calc(a[i], x);
			if (sum > b) return 0;
		}
		return 1;
	}
public:
	int calcmin(vector <int>, int);
};

int CartInSupermarket::calcmin(vector <int> A, int B) {
	int low = 1, high = 0;
	a = A; b = B;
	for (int x: a) high = max(high, x);
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}
	return low;
}
//Powered by [KawigiEdit] 2.0!
