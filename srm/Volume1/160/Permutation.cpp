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
const int f[] = {2, 3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19, 
	23, 27, 25, 29, 31, 32, 36, 37, 41, 43, 47, 49};

class Permutation {
	int lcm(int x, int y) {
		return x / gcd(x, y) * y;
	}
	int gcd(int x, int y) {
		return (x == 0) ? y : gcd(y % x, x);
	}
	int maxV;
	void dfs(int x, int now, int f) {
		if (x < now) {
			maxV = max(maxV, f);
			return;
		}
		for (int i = now; i <= x; i ++) {
			dfs(x - i, i + 1, lcm(f, i));
		}
	}
	char getV(int x) {
		if (x < 26) return 'A' + x;
		return 'a' + (x - 26);
	}
public:
	string best(int);
};

string Permutation::best(int n) {
	maxV = 0;
	dfs(n, 2, 1);
	vector<int> ret;
	int sum = n;
	for (int i = 2; i <= n; i ++) {
		if (maxV % i == 0) {
			int cnt = 1;
			while(maxV % i == 0) {
				maxV /= i;
				cnt *= i;
			}
			ret.push_back(cnt);
			sum -= cnt;
		}
	}
	
	while (sum --) ret.push_back(1);
	sort(ret.begin(), ret.end());
	//for (int i = 0; i < ret.size(); i ++) printf("%d ", ret[i]); puts("");
	int now = 0;
	string ans = "";
	for (int i = 0; i < ret.size(); i ++) {
		int f = now ++, k = ret[i];
		for (int j = 1; j < k; j ++) {
			ans += getV(now ++);
		}
		ans += getV(f);
	}
	return ans;
}