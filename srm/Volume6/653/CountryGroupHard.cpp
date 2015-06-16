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

const int maxn = 110;

using namespace std;

class CountryGroupHard {
	int c[maxn];
	int n;
	int ans[maxn];
	int check(int x, int y) {
		int k = 0;
		for (int i = x; i <= y; i ++) if (c[i]) {
			if (c[i] != (y - x + 1)) return 0;
			k = 1;
		}
		if (k == 0 && y != x) return 2;
		return 1;
	}
public:
	string solve(vector <int>);
};

string CountryGroupHard::solve(vector <int> a) {
	n = a.size();
	for (int i = 1; i <= n; i ++) c[i] = a[i - 1];
	ans[0] = 1;
	for (int i = 1; i <= n; i ++) {
		int cnt = 0;
		for (int j = 0; j < i; j ++) {
			cnt += ans[j] * check(j + 1, i);
		}
		if (cnt >= 2) cnt = 2;
		ans[i] = cnt;		
	}
	if (ans[n] >= 2) return "Insufficient";
	return "Sufficient";
}

//Powered by [KawigiEdit] 2.0!
