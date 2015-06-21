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

class Rochambo {
	int predict(int x1, int x2) {
		int t = 0;
		if (x1 == x2) t = x1;
		else {
			if (x1 > x2) swap(x1, x2);
			if (x1 != 0) t = 0;
			else if (x2 != 2) t = 2;
			else t = 1;
		}
		return (t + 1) % 3;
	}
	int check(int x1, int x2) {
		if (x1 == 0) x1 = 3;
		return x1 == x2 + 1;
	}
public:
	int wins(string);
};

int Rochambo::wins(string s) {
	int p1 = 0, p2 = 0, n = s.length(), ans = 0;
	for (int i = 0; i < n; i ++) {
		int now = 0;
		if (s[i] == 'P') now = 1;
		else if (s[i] == 'S') now = 2;
		if (i < 2) {
			ans += check(0, now);
		} else {
			ans += check(predict(p1, p2), now);
		}
		p2 = p1;
		p1 = now;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
