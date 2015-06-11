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

class FixedPointTheorem {
public:
	double cycleRange(double);
};

double FixedPointTheorem::cycleRange(double R) {
	double high = -1e20, low = 1e20, x = 0.25;
	for (int i = 0; i < 201000; i ++) {
		x = R * x * (1 - x);
		if (i >= 200000) {
			high = max(high, x);
			low = min(low, x);
		}
	}
	return high - low;
}

//Powered by [KawigiEdit] 2.0!
