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
typedef long long ll;
const int MAXP = 32000;
const int MAXN = 1010;
const int MOD = 1e9 + 7;
using namespace std;

class TwoNumberGroups {
	int p[MAXP], len;
	void init() {
		len = 0;
		for (int i = 2; i < MAXP; i ++) {
			int ok = 1;
			for (int j = 0; j < len && p[j] * p[j] <= i && ok; j ++) ok = (i % p[j] != 0);
			if (ok) p[len ++] = i;
		}
	}
	vector<int> ret[MAXN];
	vector<int> r[MAXN];
public:
	int solve(vector <int>, vector <int>, vector <int>, vector <int>);
};

int TwoNumberGroups::solve(vector <int> A, vector <int> numA, vector <int> B, vector <int> numB) {
	init();
	int n = A.size(), m = B.size();
	ll ans = 0;
	for (int i = 0; i < n; i ++) {
		ret[i].resize(m, 0);
		for (int j = 0; j < m; j ++) r[i].push_back(abs(A[i] - B[j]));
	}
	for (int i = 0; i < len; i ++) {
		vector<list<int> > mod(p[i]);
		for (int j = 0; j < n; j ++) mod[A[j] % p[i]].push_back(j);
		for (int j = 0; j < m; j ++) {
			for (int k: mod[B[j] % p[i]]) if (r[k][j]) {
				ret[k][j] += p[i];
				r[k][j] /= p[i];
				while (r[k][j] % p[i] == 0) r[k][j] /= p[i];
			}
 		}
	}
	for (int i = 0; i < n; i ++) {
		ll now = 0;
		for (int j = 0; j < m; j ++) {
			if (r[i][j] != 1) ret[i][j] += r[i][j];
			now += (ll)ret[i][j] * numB[j];
		} 
		ans += now % MOD * numA[i];
	}
	return ans % MOD;
}
//Powered by [KawigiEdit] 2.0!
