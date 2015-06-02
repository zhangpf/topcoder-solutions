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
#include <memory>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long ll;

class Flags {
	ll c[20][20];
	ll s[20][20], tmp[20][20];
	ll m;
	int n;
	int calc(ll x[][20], ll z[][20]) {
		memset(tmp, 0, sizeof(tmp));
		ll sum = 0;
		int of = 0;
		for (int k = 0; !of && k < n; k++) {
			for (int j = 0; !of && j < n; j++) if (z[k][j]) {
				for (int i = 0; !of && i < n; i++) {
					if (m / z[k][j] < x[i][k]) of = 1;
					tmp[i][j] += z[k][j] * x[i][k];
					if (m <= tmp[i][j]) of = 1;
				}
			}	
		}
		if (of) return 1;
		for (int i = 0; !of && i < n; i++) {
			for (int j = 0; !of && j < n; j++) {
				sum += tmp[i][j];
				if (sum >= m) of = 1;
				x[i][j] = tmp[i][j];
			}
		}
		return 0;
	}
	
	ll check(ll x) {
		int of = 0;
		memset(s, 0, sizeof(s));
		for (int i = 0; i < n; i++) s[i][i] = 1;
		int i = 0;
		while (x >= (1LL << i)) i++;
		for (i --; !of && i >= 0; i --) {
			of = calc(s, s);
			if (!of && (x & (1LL << i))) of = calc(s, c);
		}
		ll sum = 0;
		for (int i = 0; !of && i < n; i ++) {
			for (int j = 0; !of && j < n; j ++) {
				sum = sum + s[i][j];
				if (sum >= m) of = 1;
			}
		}
		return of;
	}
public:
	long long numStripes(string, vector <string>);
};

long long Flags::numStripes(string numF, vector <string> f) {
	stringstream sin(numF);
	sin >> m;
	n = f.size();
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j++) c[i][j] = 1;
	for (int i = 0; i < n; i ++) {
		stringstream sin(f[i]);
		int x;
		while(sin >> x) c[i][x] = 0; 
	}
	n ++; 
	for (int i = 0; i < n; i ++) c[i][n-1] = 1;
	m ++;
	ll low = 0, high = m - 1;
	while (low < high) {
		ll mid = (low + high) / 2;
		if (check(mid)) high = mid;
		else low = mid + 1;
	}
	return high + 1;
}
//Powered by [KawigiEdit] 2.0!

