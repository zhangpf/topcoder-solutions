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

class BirthdayOdds {
public:
	int minPeople(int, int);
};

int BirthdayOdds::minPeople(int y, int x) {
	int ans = 0;
	while (1) {
		ans ++;
		double ret = 1, b = 1 - y / 100.;
		for (int i = 0; i < ans; i ++) {
			ret = ret * (x - i) / x;
		}
		if (ret < b + 1e-9) break;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
