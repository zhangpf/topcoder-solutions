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

class LCMRange {
	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}
	int lcmSingle(int x, int y) {
		return x / gcd(x, y) * y;
	}
public:
	int lcm(int, int);
};

int LCMRange::lcm(int s, int t) {
	int now = 1;
	for (int i = s; i <= t; i ++) {
		now = lcmSingle(now, i);
	}
	return now;
}

//Powered by [KawigiEdit] 2.0!
