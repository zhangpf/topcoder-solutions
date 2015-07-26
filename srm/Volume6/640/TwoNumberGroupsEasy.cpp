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

class TwoNumberGroupsEasy {
	vector<int> factor(int x) {
		vector<int> ans;
		for (int i = 1; i * i <= x; i ++) if (x % i == 0) {
			if (i != 1) ans.push_back(i);
			if (x/i != i) ans.push_back(x/i);
		}
		return ans;
	}
	int calc(int x, vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
		map<int, int> c;
		for (int u = 0; u < A.size(); u ++) c[A[u] % x] += numA[u];
		for (int v = 0; v < B.size(); v ++) c[B[v] % x] -= numB[v];
		int now = 0;
		for (auto y: c) {
			now += abs(y.second);
		}
		return now;
	}
public:
	int solve(vector <int>, vector <int>, vector <int>, vector <int>);
};

int TwoNumberGroupsEasy::solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
	int n = A.size();
	int m = B.size();
	int ans = calc(INF, A, numA, B, numB);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int k = abs(A[i] - B[j]);
			vector<int> f = factor(k);
			for (int x: f) {
				ans = min(ans, calc(x, A, numA, B, numB));
			}
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
