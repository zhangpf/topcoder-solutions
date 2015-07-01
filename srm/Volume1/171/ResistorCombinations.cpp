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
double fcmp(double x) {
	if (x < -1e-9) return -1;
	return x > 1e-9;
}

class ResistorCombinations {
	int n;
public:
	double closestValue(vector <string>, double);
};

double ResistorCombinations::closestValue(vector <string> r, double t) {
	n = r.size();
	vector<double> re(n);
	for (int i = 0; i < n; i ++) {
		stringstream sin(r[i]);
		sin >> re[i];
	}
	vector<double> res[32];
	double ans = -1e30;
	for (int i = 1; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) if ((1 << j) == i) {
			res[i].push_back(re[j]);
			if (fcmp(fabs(ans - t) - fabs(re[j] - t)) > 0)  ans = re[j];
		}
		vector<double> tmp;
		for (int j = 1; j + j <= i; j ++) if ((i & j) == j) {
			int k = i - j;
			for (double u: res[j]) {
				for (double v: res[k]) {
					tmp.push_back(u + v);
					tmp.push_back(1 / (1 / u + 1 / v));
				}
			}
		}
		sort(tmp.begin(), tmp.end());
		for (double it: tmp) {
			if (res[i].size() && fcmp(it - res[i][res[i].size() - 1]) == 0) continue;
			if (fcmp(fabs(ans - t) - fabs(it - t)) > 0)  ans = it;
			res[i].push_back(it);
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
