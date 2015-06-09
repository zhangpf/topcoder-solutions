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

class BigBurger {
public:
	int maxWait(vector <int>, vector <int>);
};

int BigBurger::maxWait(vector <int> b, vector <int> e) {
	int ans = 0, now = 0;
	for (int i = 0; i < e.size(); i ++) {
		if (now > b[i]) {
			ans = max(ans, now - b[i]);
		} else now = b[i];
		now += e[i];
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
