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
typedef int ll;

using namespace std;
class ProblemSetsEasy {
	ll a, b, c, d, e;
	int check(ll x) {
		ll fa = a, fb = b, fc = c, fd = d, fe = e;
		if (fa + fb < x) return 0;
		if (x > fa) fb -= (x - fa);
		if (fb + fd + fc < x) return 0;
		if (x > fb + fc) fd -= (x - fb - fc);
		return (fd + fe) >= x;
	}
public:
	int maxSets(int, int, int, int, int);
};

int ProblemSetsEasy::maxSets(int E, int EM, int M, int MH, int H) {
	ll low = 0, high = (E + EM + M + MH + H) / 3;
	a = E, b = EM, c = M, d = MH, e = H;
	while (low < high) {
		ll mid = (low + high + 1) / 2;
		if (check(mid)) low = mid;
		else high = mid - 1;
	}
	return low;
}

//Powered by [KawigiEdit] 2.0!
