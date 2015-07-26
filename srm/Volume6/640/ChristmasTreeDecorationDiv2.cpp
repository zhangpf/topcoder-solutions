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

class ChristmasTreeDecorationDiv2 {
public:
	int solve(vector <int>, vector <int>, vector <int>);
};

int ChristmasTreeDecorationDiv2::solve(vector <int> col, vector <int> x, vector <int> y) {
	int ans = 0;
	for (int i = 0; i < x.size(); i ++) {
		int u = x[i] - 1, v = y[i] - 1;
		if (col[u] != col[v]) ans ++;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
