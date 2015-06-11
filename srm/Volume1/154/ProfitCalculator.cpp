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

class ProfitCalculator {
public:
	int percent(vector <string>);
};

int ProfitCalculator::percent(vector <string> items) {
	double k1 = 0, k2 = 0;
	for (int i = 0; i < items.size(); i ++) {
		stringstream sin(items[i]);
		double x, y;
		sin >> x >> y;
		//printf("%lf %lf\n", x, y);
		k1 += x;
		k2 += y;
	}
	printf ("%lf %lf\n", k1, k2);
	return (int)((k1 - k2) * 100 / k1);
}

//Powered by [KawigiEdit] 2.0!
