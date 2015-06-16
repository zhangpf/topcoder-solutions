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
#include <memory>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int inf = 0x3fffffff;
const int maxn = 30;

class BridgeBuildingDiv2 {
	int a[maxn][maxn];
	int n;
public:
	int minDiameter(vector <int>, vector <int>, int);
};

int BridgeBuildingDiv2::minDiameter(vector <int> A, vector <int> B, int K) {
	int d = inf;
	n = A.size() + 1;
	for (int i = 0; i < (1 << n); i ++) {
		int cnt = 0;
		memset(a, 0xff, sizeof(a));
		for (int j = 0; j < n; j ++) {
			if (i & (1 << j)) {
				a[j][j + n] = 0;
				a[j + n][j] = 0;
				cnt ++;
			}
		}
		if (cnt != K) continue;
		for (int j = 0; j < n + n; j ++) {
			for (int k = j; k < n + n; k ++) {
				if (a[j][k] == -1) {
					if (j == k) a[j][k] = 0;
					else if (j + 1 == k && j < n - 1) a[j][k] = a[k][j] = A[j];
					else if (j + 1 == k && j >= n) a[j][k] = a[k][j] = B[j - n];
					else a[j][k] = a[k][j] = inf;
				}
			}
		}
		for (int j = 0; j < n + n; j ++) {
			for (int k = 0; k < n + n; k ++) {
				for (int t = 0; t < n + n; t ++) {
					a[k][t] = min(a[k][t], a[k][j] + a[j][t]);
				}
			}
		}
		int maxV = 0;
		for (int j = 0; j < n + n; j ++) {
			for (int k = 0; k < n + n; k ++) {
				maxV = max(maxV, a[j][k]);
			}
		} 
		d = min(d, maxV);
	}
	return d;
}

//Powered by [KawigiEdit] 2.0!
