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
const double L1 = sqrt(3.0);

class JarBox {
	int r, len;
	int check(int x) {
		for (int i = 1; i <= x; i ++) {
			int w = x / i;
			if (x - w * i == 0) w = w + w + 1;
			else if (x - w * i > (i + 1) / 2) w = w + w + 3;
			else w = w + w + 2;
			double sum = (w * 2 + (i - 1) * 2 * L1 + 4) * r;
			//printf("%d %d %d %lf\n", x, i, w, sum);
			if (sum <= len - 1e-5) return 1;
		}
		return 0;
	}
public:
	int numJars(int, int);
};

int JarBox::numJars(int R, int L) {
	len = L, r = R;
	int low = 1, high = 2000000;
	while (low < high) {
		int mid = (low + high + 1) >> 1;
		if (check(mid)) low = mid;
		else high = mid - 1;
	}
	return low;
}

//Powered by [KawigiEdit] 2.0!
