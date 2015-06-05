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
#include <memory>
#include <cstring>

using namespace std;

const int maxn = 110;

class Coversta {
	map<pair<int, int>, int> c;
	int f[maxn][maxn];
	int h[maxn][maxn];
	int a[maxn][maxn];
	int n, m, k;
	int getId(int x, int y) {
		if (x < 0 || x >= n || y < 0 || y >= m) return -1;
		return x * m + y;
	}
public:
	int place(vector <string>, vector <int>, vector <int>);
};

int Coversta::place(vector <string> A, vector <int> x, vector <int> y) {
	n = A.size();
	m = A[0].length();
	for (int i = 0; i < n; i ++) for (int j = 0; j < m; j++) a[i][j] = A[i][j] - '0';
	k = x.size();
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			for (int t = 0; t < k; t ++) {
				int d = getId(i + x[t], j + y[t]);
				if (d == -1) continue;
				f[i][j] += a[i+x[t]][j+y[t]];
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
		memset(h, 0, sizeof(h));
		for (int t = 0; t < k; t ++) for (int s = 0; s < k; s ++){
			int x1 = i + x[t] - x[s];
			int y1 = j + y[t] - y[s];
			int x2 = i + x[t];
			int y2 = j + y[t];
			if (getId(x1, y1) != -1 && getId(x2, y2) != -1) {
				h[x1][y1] -= a[x2][y2];
			}
		}
		for (int t = 0; t < n; t ++) for (int s = 0; s < m; s ++) {
			ans = max(ans, h[t][s] + f[i][j] + f[t][s]);
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!