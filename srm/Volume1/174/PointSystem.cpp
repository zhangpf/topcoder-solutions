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
#include <cstring>
#include <memory>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
const double EPS = 1e-12;
const int MAXN = 2010;
const int MAXL = 2000;

using namespace std;
double dcmp(double x) {
	if (x < -EPS) return -1;
	return x > EPS;
}

class PointSystem {
	double ans[MAXN][MAXN];
public:
	double oddsOfWinning(int, int, int);
};

double PointSystem::oddsOfWinning(int n, int m, int p) {
	memset(ans, 0, sizeof(ans));
	double ret = 0;
	ans[0][0] = 1;
	for (int i = 0; i < MAXL; i ++) {
		for (int j = 0; j <= i; j ++) {
			int k = i - j;
			if (j >= n && j - k >= m) {
				ret += ans[i][j];
				continue;
			} else if (k >= n && k - j >= m) continue;
			ans[i + 1][j] += ans[i][j] * (100 - p) / 100;
			ans[i + 1][j + 1] += ans[i][j] * p / 100;
		}
	}
 	return ret;
}

//Powered by [KawigiEdit] 2.0!
