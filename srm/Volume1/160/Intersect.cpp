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
const int inf = 0x3ffff;

class Intersect {
public:
	int area(vector <int>, vector <int>);
};

int Intersect::area(vector <int> x, vector <int> y) {
	int x1 = -inf, x2 = inf, y1 = -inf, y2 = inf;
	for (int i = 0; i < x.size() / 2; i ++) {
		int ox2 = max(x[i + i], x[i + i + 1]);
		int ox1 = min(x[i + i], x[i + i + 1]);
		int oy1 = min(y[i + i], y[i + i + 1]);
		int oy2 = max(y[i + i], y[i + i + 1]);
		
		x1 = max(x1, ox1);
		y1 = max(y1, oy1);
		x2 = min(x2, ox2);
		y2 = min(y2, oy2);
	}
	//printf("%d %d %d %d\n", x1, y1, x2, y2);
	return max(0, (x2 - x1)) * max(0, (y2 - y1));
}

//Powered by [KawigiEdit] 2.0!
