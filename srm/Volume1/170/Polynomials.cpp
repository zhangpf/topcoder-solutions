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
using namespace std;

class Polynomials {
	void getI(string s, int &x, int &y, char &c) {
		if (s.length() == 1) { 
			x = 0; 
			y = s[0] - '0'; 
		}
		else {
			y = s[0] - '0';
			x = s[3] - '0';
			if (y && x) c = s[1];
		}
	}
	vector<int> parse(string s, char &c) {
		int now = 0, nx;
		vector<int> ans(10);
		int x, y;
		while ((nx = s.find('+', now)) != std::string::npos) {
			getI(s.substr(now, nx - now), x, y, c);
			ans[x] += y;
			now = nx + 1;
		}
		getI(s.substr(now), x, y, c);
		ans[x] += y;
		return ans;
	}
	ll calc(vector<int> &p, int x) {
		ll ans = 0, now = 1;
		for (int i = 0; i < 10; i ++) {
			ans += now * p[i];
			now *= x;
		}
		return ans;
	}
public:
	long long integralPoints(int, int, string);
};

long long Polynomials::integralPoints(int ymax, int xmax, string s) {
	int p = s.find('=');
	char cl = 0, cr = 0;
	vector<int> l = parse(s.substr(0, p), cl);
	vector<int> r = parse(s.substr(p + 1), cr);
	vector<int> x, y;
	if (cl == 0 && cr == 0) {
		if (l[0] == r[0]) return (ll)(1 + ymax) * (1 + xmax);
		else return 0LL;	
	} else if (cl == 0) {
		x = l; y = r; swap(xmax, ymax);
	} else {
		x = r; y = l;
	}
	int ans = 0;
	for (int i = 0; i <= xmax; i ++) {
		ll left = calc(x, i); 
		int low = 0, mid, high = ymax, ok = 0;
		while (low <= high && !ok) {
			mid = (low + high) >> 1;
			ll r = calc(y, mid);
			if (r == left) ok = 1;
			else if (r > left) high = mid - 1;
			else low = mid + 1;
		}
		if (ok) ans ++;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
