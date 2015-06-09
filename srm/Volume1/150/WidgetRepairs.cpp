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

class WidgetRepairs {
public:
	int days(vector <int>, int);
};

int WidgetRepairs::days(vector <int> a, int b) {
	int now = 0, cnt = 0;
	for (int i = 0; i < a.size(); i ++) {
		now += a[i];
		if (now != 0) cnt ++;
		now -= min(now, b);
		//printf ("%d %d %d\n", a[i], now, cnt);
	}
	if (now != 0) cnt += (now + b - 1) / b;
	return cnt;
}
//Powered by [KawigiEdit] 2.0!
