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
const int inf = 0x3fffff;

class MutaliskEasy {
	int ans[61][61][61];
	int b(int x) {
		return max(x, 0);
	}
public:
	int minimalAttacks(vector <int>);
};

int MutaliskEasy::minimalAttacks(vector <int> x) {
	for (int i = 0; i <= 60; i ++) {
		for (int j = 0; j <= 60; j ++) for (int k = 0; k <= 60; k++) {
			if (i == 0 && j == 0 && k == 0) ans[i][j][k] = 0;
			else {
				int ret = inf;
				ret = min(ret, ans[b(i-9)][b(j-3)][b(k-1)]);
				ret = min(ret, ans[b(i-3)][b(j-9)][b(k-1)]);
				ret = min(ret, ans[b(i-9)][b(j-1)][b(k-3)]);
				ret = min(ret, ans[b(i-3)][b(j-1)][b(k-9)]);
				ret = min(ret, ans[b(i-1)][b(j-3)][b(k-9)]);
				ret = min(ret, ans[b(i-1)][b(j-9)][b(k-3)]); 
				ans[i][j][k] = ret + 1;
			}
		}
	}
	if (x.size() == 1) return ans[x[0]][0][0];
	if (x.size() == 2) return ans[x[0]][x[1]][0];
	return ans[x[0]][x[1]][x[2]];
}
//Powered by [KawigiEdit] 2.0!
