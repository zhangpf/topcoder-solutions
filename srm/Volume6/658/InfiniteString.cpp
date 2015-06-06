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

class InfiniteString {
public:
	string equal(string, string);
};

string InfiniteString::equal(string s, string t) {
	int n = s.length(), m = t.length();
	for (int i = 0; i < n * m; i ++) {
		if (s[i % n] != t[i % m]) return "Not equal";
	}
	return "Equal";
}

//Powered by [KawigiEdit] 2.0!
