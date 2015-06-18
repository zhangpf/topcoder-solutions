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
#include <cstring>
#include <memory>

using namespace std;

class PermutationCounter {
	long long c[50][50];
	long long C(int x, int y) {
		//printf("%d %d\n", x, y);
		if (c[x][y] != -1) 
			return c[x][y];
		if (x < 0 || x < y) return 0;
		if (x == y || y == 0) return c[x][y] = 1;
		return c[x][y] = C(x - 1, y - 1) + C(x - 1, y);
	}
	long long calc(int len, vector<int> p) {
		//printf("%d\n", len);
		int sum = 0;
		for (int i = 1; i < 10; i ++) sum += p[i];
		if (sum > len) return 0;
		long long ans = 1;
		for (int i = 1; i < 10; i ++) {
			ans *= C(len, p[i]);
			len -= p[i];
		}
		return ans;	
	}
public:
	long long count(string);
};

long long PermutationCounter::count(string s) {
	int n = s.length();
	vector<int> cnt(10);
	memset(c, 0xff, sizeof(c));
	for (int i = 0; i < n; i ++) cnt[s[i] - '0'] ++;
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < s[i] - '0'; j ++) if (j == 0 || cnt[j]) {
			cnt[j] --;
			ans += calc(n - i - 1, cnt);
			cnt[j] ++;
		}
		cnt[s[i] - '0'] --;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
