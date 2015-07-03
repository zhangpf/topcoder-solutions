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

class BadClock {
	int calc(string s) {
		int hh = (s[0] - '0') * 10 + (s[1] - '0');
		int mm = (s[3] - '0') * 10 + (s[4] - '0');
		int ss = (s[6] - '0') * 10 + (s[7] - '0');
		return hh * 3600 + mm * 60 + ss;
	}
public:
	double nextAgreement(string, string, int);
};

double BadClock::nextAgreement(string trueTime, string skewTime, int g) {
	int x = calc(trueTime), y = calc(skewTime);
	int diff = y - x;
	if (diff == 0) return 0;
	printf("%d %d\n", diff, g);
	if (g < 0 && diff < 0) diff += 43200; 
	if (g > 0 && diff > 0) diff -= 43200;
	return -1.0 * diff / g;
}
//Powered by [KawigiEdit] 2.0!
