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
const int maxn = 60;
const int inf = 0x3fffffff;

using namespace std;

class GasStations {
	class station {
	public:
		int p, d;
		friend int operator < (const station &s1, const station &s2) {
			return s1.d < s2.d;
		}
	} t[maxn];
	
	int n;
public:
	double tripCost(vector <int>, vector <int>, int, int, int);
};

double GasStations::tripCost(vector <int> d, vector <int> p, int mpg, int sz, int m) {
	n = d.size();
	for (int i = 0; i < n; i ++) {
		t[i].p = p[i]; t[i].d = d[i];
	}
	t[n].p = inf, t[n].d = 0, n ++;
	t[n].p = 0, t[n].d = m, n ++;
	sort(t, t + n);
	double ans = 0;
	int now = mpg * sz;
	for (int i = 0; i < n - 1;) {
		int found = 0;
		for (int j = i + 1; !found && j < n; j ++) {
			if (t[j].d - t[i].d > mpg * sz) break;
			if (t[j].p < t[i].p) found = j;
		}
		if (found) {
			if (t[found].d - t[i].d > now) {
				ans += (t[found].d - t[i].d - now) * 1.0 / mpg * t[i].p;
				now = 0;
			} else {
				now -= (t[found].d - t[i].d);
			}
			i = found;
		} else {
			ans += (mpg * sz - now) * 1.0 / mpg * t[i].p;
			now = mpg * sz - (t[i + 1].d - t[i].d);
			i ++;
		}
	//	printf("%d %d %lf\n", found, now, ans);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
