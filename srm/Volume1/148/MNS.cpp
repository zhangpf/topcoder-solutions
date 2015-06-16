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

class MNS {
	set<int> magic;
	int t[9];
	int b[3][3];
	void dfs (int d, int s, int v) {
		if (d == 9) {
			int k = b[0][0] + b[0][1] + b[0][2];
			if (b[1][0] + b[1][1] + b[1][2] != k) return;
			if (b[2][0] + b[2][1] + b[2][2] != k) return;
			if (b[0][0] + b[1][0] + b[2][0] != k) return;
			if (b[0][1] + b[1][1] + b[2][1] != k) return;
			if (magic.find(v) == magic.end()) 
				magic.insert(v);
		}
		for (int i = 0; i < 9; i ++) if ((s & (1 << i)) == 0) {
			b[d / 3][d % 3] = t[i];
			dfs(d + 1, s | (1 << i), v * 10 + t[i]);
		}
	}
public:
	int combos(vector <int>);
};

int MNS::combos(vector <int> numbers) {
	for (int i = 0; i < 9; i ++) t[i] = numbers[i];
	dfs(0, 0, 0);
	return magic.size();
}
//Powered by [KawigiEdit] 2.0!
