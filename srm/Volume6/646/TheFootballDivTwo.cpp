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
typedef long long ll;

using namespace std;

class TheFootballDivTwo {
public:
	int find(int, vector <int>, vector <int>);
};

int TheFootballDivTwo::find(int y, vector <int> s, vector <int> t) {
	ll a = 0, b = 0, c = 0, d = 0;
	int n = s.size();
	y += 6;
	for (int i = 0; i < n; i ++) {
		if (s[i] <= y - 6 || s[i] > y) {
			a += t[i];
			if (s[i] > y) {
				d += t[i];
			}
		}
		else if (s[i] > y - 6 && s[i] <= y - 3) c += t[i];
		else b += t[i];
	}
	ll r = a + b + c - 1;
	if (a + a >= r) return d + 1;
	r -= (a + a);
	if (c >= r) return d + 1;
	r -= c;
	if (r <= b + b) return (r + 1) / 2 + d + 1;
	r -= (b + b);
	return d + b + 1 + r;
}
//Powered by [KawigiEdit] 2.0!
