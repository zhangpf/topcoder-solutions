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

class CtuRobots {
public:
	double maxDist(int, vector <int>, vector <int>);
};

double CtuRobots::maxDist(int B, vector <int> cost, vector <int> cap) {
	int n = cost.size();
	vector<pair<int, int> > x(n);
	for (int i = 0; i < n; i ++) x[i] = make_pair(cap[i], cost[i]);
	sort(x.begin(), x.end());
	vector<double> ans(B + 1, 0);
	for (int i = 0; i < n; i ++) {
		int c = x[i].second;
		int p = x[i].first;
		for (int j = B; j >= c; j --) {
			ans[j] = max(ans[j], ans[j - c] / 3 + p);
		}
	}
	double ret = 0;
	for (int i = 0; i <= B; i ++) ret = max(ret, ans[i]);
	return ret / 2.0;
}

//Powered by [KawigiEdit] 2.0!
