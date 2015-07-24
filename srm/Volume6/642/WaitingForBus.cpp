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
#include <cstring>
#include <memory>

using namespace std;
const int MAXN = 100010;

class WaitingForBus {
	double ans[MAXN];
public:
	double whenWillBusArrive(vector <int>, vector <int>, int);
};

double WaitingForBus::whenWillBusArrive(vector <int> t, vector <int> p, int s) {
	int n = t.size();
	memset(ans, 0, sizeof(ans));
	ans[0] = 1;
	double ret = 0;
	for (int i = 0; i < s; i ++) {
		for (int j = 0; j < n; j ++) {
			double k = ans[i] * p[j] / 100;
			if (i + t[j] >= s) ret += k * (i + t[j] - s);
			else ans[i + t[j]] += k; 
		}
	}
	return ret;
}
//Powered by [KawigiEdit] 2.0!
