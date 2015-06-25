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

class ConvexPolygon {
public:
	double findArea(vector <int>, vector <int>);
};

double ConvexPolygon::findArea(vector <int> x, vector <int> y) {
	double ans = 0;
	for (int i = 0; i < x.size(); i ++) {
		ans += (x[(i + 1) % x.size()] * y[i] - y[(i + 1) % x.size()] * x[i]);
	}
	return abs(ans / 2);
}

//Powered by [KawigiEdit] 2.0!
