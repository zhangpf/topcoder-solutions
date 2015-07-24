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

class LightSwitchingPuzzle {
public:
	int minFlips(string);
};

int LightSwitchingPuzzle::minFlips(string s) {
	int ans = 0;
	for (int i = 0; i < s.length(); i ++) {
		if (s[i] == 'N') continue;
		ans ++;
		for (int j = i; j < s.length(); j += (i + 1)) {
			s[j] = (s[j] == 'Y') ? 'N' : 'Y';
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
