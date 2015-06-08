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
const int INF = 0x3fffffff;

class FoldingPaper2 {
	int calc (int x, int y) {
		if (x > y) return INF;
		int res = 0;
		while (x < y) {
			res ++;
			x <<= 1;
		}
		return res;
	}
public:
	int solve(int, int, int);
};

int FoldingPaper2::solve(int W, int H, int A) {
	int ans = INF;
	for (int i = 1; i <= A; i ++) if (A % i == 0) {
		ans = min(ans, calc(i, W) + calc(A / i, H));
	}
	if (ans == INF) ans = -1;
	return ans;
}

//Powered by [KawigiEdit] 2.0!
