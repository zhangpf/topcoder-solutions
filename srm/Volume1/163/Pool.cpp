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

const int p[2][15] = {
	{0, 1, 1, 0, 2, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1},
	{1, 0, 0, 1, 2, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0}
};
class Pool {
	int calc(int x) {
		if (x <= 7) return 0;
		if (x == 8) return 2;
		else return 1;
	}
public:
	int rackMoves(vector <int>);
};

int Pool::rackMoves(vector <int> t) {
	int ret = 20;
	for (int i = 0; i < 2; i ++) {
		int f1 = 0, f2 = 0, f3 = 0;
		for (int j = 0; j < 15; j ++) if (calc(t[j]) != p[i][j]) {
			if (p[i][j] == 0) f1 ++;
			else if (p[i][j] == 1) f2 ++;
			else f3 ++;
		}
		//printf("%d %d %d\n", f1, f2, f3);
		if (f3 == 1 && f2 == f1) ret = min(ret, max(f2, f1) + 1);
		else ret = min(ret, max(f2, f1));
	}
	return ret;
}
//Powered by [KawigiEdit] 2.0!
