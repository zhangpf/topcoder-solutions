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

class FormatAmt {
	string calc(int x, int w) {
		string ans = "";
		if (w >= 3 && x < 100) ans += '0';
		if (w >= 2 && x < 10) ans += '0';
		ans += to_string(x);
		return ans;
	}
public:
	string amount(int, int);
};

string FormatAmt::amount(int d, int c) {
	string ans = "$";
	if (d == 0)
		ans += '0';
	else if (d < 1000)
		ans += to_string(d);
	else if (d < 1000000)
		ans += to_string(d / 1000) + ',' + calc(d % 1000, 3);
	else if (d < 1000000000)
		ans += to_string(d / 1000000) + ',' + calc(d % 1000000 / 1000, 3) \
			+ ',' + calc(d % 1000, 3);
	else 
		ans += to_string(d / 1000000000) + ',' + calc(d % 1000000000 / 1000000, 3) \
			+ ',' + calc(d % 1000000 / 1000, 3) + ',' + calc(d % 1000, 3);
	ans += '.' + calc(c, 2);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
