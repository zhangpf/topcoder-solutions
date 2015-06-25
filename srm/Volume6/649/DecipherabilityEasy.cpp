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

class DecipherabilityEasy {
public:
	string check(string, string);
};

string DecipherabilityEasy::check(string s, string t) {
	for (int i = 0; i < s.length(); i ++) {
		if (t == s.substr(0, i) + s.substr(i + 1))
			return "Possible";
	}
	return "Impossible";
}
//Powered by [KawigiEdit] 2.0!
