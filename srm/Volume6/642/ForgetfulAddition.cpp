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

class ForgetfulAddition {
	int calc(string s1, string s2) {
		stringstream sin1(s1), sin2(s2);
		int x, y;
		sin1 >> x; sin2 >> y;
		return x + y;
	}
public:
	int minNumber(string);
};

int ForgetfulAddition::minNumber(string s) {
	int ans = 0x3fffffff;
	for (int i = 1; i < s.length(); i ++) {
		ans = min(ans, calc(s.substr(0, i), s.substr(i)));
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
