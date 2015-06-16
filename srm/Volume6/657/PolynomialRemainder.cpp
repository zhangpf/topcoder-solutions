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
typedef long long ll;

class PolynomialRemainder {
	int a, b, c;
	int calc(int x) {
		for (int i = 0; i < x; i++) {
			if ((((ll)a * i % x) * i + (ll)b * i + c) % x == 0) return i;
		}
		return -1;
	}
public:
	int findRoot(int, int, int);
};

int PolynomialRemainder::findRoot(int A, int B, int C) {
	a = A, b = B, c = C;
	int s1 = calc(512);
	int s2 = calc(1953125);
	if (s1 == -1 || s2 == -1) return -1;
	for (int i = 0; i < 512; i ++) {
		int now = s2 + 1953125 * i;
		if (now % 512 == s1) {
			return now;
		}
	}
	return -1;
}
