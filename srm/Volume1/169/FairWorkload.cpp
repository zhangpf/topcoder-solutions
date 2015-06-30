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
#include <cstring>
#include <memory>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class FairWorkload {
	vector<int> f;
	int n;
	int ans[20][20];
	int total (int x, int y) {
		int sum = 0;
		for (int i = x; i < y; i ++) sum += f[i];
		return sum;
	}
	int calc (int x, int y) {
		if (ans[x][y] != -1)
			return ans[x][y];
		
		if (y == 1) return ans[x][y] = total(x, n);
		ans[x][y] = 0x3fffffff;
		for (int i = x + 1; i <= n - (y - 1); i ++) {
			ans[x][y] = min(ans[x][y], max(total(x, i), calc(i, y - 1)));
		}
		return ans[x][y];
	}
public:
	int getMostWork(vector <int>, int);
};

int FairWorkload::getMostWork(vector <int> folders, int workers) {
	f = folders;
	memset(ans, 0xff, sizeof(ans));
	n = f.size();
	return calc(0, workers);
}

//Powered by [KawigiEdit] 2.0!
