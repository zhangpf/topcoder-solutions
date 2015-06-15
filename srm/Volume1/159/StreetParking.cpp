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

class StreetParking {
public:
	int freeParks(string);
};

int StreetParking::freeParks(string s) {
	int ans = 0;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'B' || s[i] == 'D' || s[i] == 'S') continue;
		if (i + 2 < s.size() && s[i + 2] == 'B') continue;
		if (i + 1 < s.size() && s[i + 1] == 'B') continue;
		if (i + 1 < s.size() && s[i + 1] == 'S') continue;
		if (i - 1 >= 0 && s[i - 1] == 'S') continue;
		ans ++;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
