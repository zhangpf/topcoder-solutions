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

class TennisRallies {
	int ans[19][1 << 18];
	int len[20], v[20];
public:
	int howMany(int, vector <string>, int);
};

int TennisRallies::howMany(int n, vector <string> f, int a) {
	int m = f.size();
	for (int i = 0; i < m; i ++) {
		len[i] = f[i].length();
		v[i] = 0;
		for (int j = 0; j < f[i].length(); j ++) {
			v[i] = v[i] * 2 + (f[i][j] != 'c');
		}
		//printf("%d %d\n", len[i], v[i]);
	}
	ans[0][0] = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 0; j < (1 << i); j ++) {
			ans[i][j] = ans[i - 1][j >> 1];
			for (int k = 0; k < m; k ++) {
				if (i < len[k]) continue;
				if ((j & ((1 << len[k]) - 1)) != v[k]) continue;
				ans[i][j] ++;
			}
			if (i == n && ans[i][j] < a) cnt ++;
		}
	}
	return cnt;
}

//Powered by [KawigiEdit] 2.0!
