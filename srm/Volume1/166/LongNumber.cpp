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
typedef long long ll;

class LongNumber {
	ll calc1(ll x) {
		x ++;
		ll d = 1, now = 1, sum = 1;
		ll ans = 0;
		while (sum < x) {
			now *= 10;
			ans += min(x - sum, now - sum) * d;
			sum = min(x, now);
			d ++;
		}
		return ans;
	}
	ll calc2(ll x) {
		x ++;
		ll d = 1, now1 = 1, sum = 1;
		ll ans = 0;
		while (sum < x) {
			if (d & 1) {
				ll now2 = (ll)(sqrt(10) * now1 + 1);
				ans += min(x - sum, now2 - sum) * d;
				sum = min(x, now2);
			} else {
				now1 *= 10;
				ans += min(x - sum, now1 - sum) * d;
				sum = min(x, now1);
			}
			d ++;
		}
		return ans;
	}
	void append(string &s, ll x) {
		string s2 = "";
		while (x) {
			s2 = (char)(x % 10 + '0') + s2;
			x /= 10;
		}
		s += s2;
	}
public:
	int findDigit(int);
};

int LongNumber::findDigit(int k) {
	int low = 1, high = k;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (calc1(mid) < k) low = mid + 1;
		else high = mid;
	}
	int k1 = low;
	low = 1, high = k;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (calc2(mid) < k) low = mid + 1;
		else high = mid;
	}
	int k2 = low;
	string s1 = "", s2 = "";
	for (int i = 0; i < 10; i ++) append(s1, k1 + i);
	for (int i = 0; i < 10; i ++) append(s2, (ll)(k2 + i) * (k2 + i));
	int len1 = calc1(k1 + 9), len2 = calc2(k2 + 9);
	while (len1 < len2) s2 = s2.substr(0, s2.length() - 1), len2 --;
	int over = 0, now1 = s1.length() - 1, now2 = s2.length() - 1;
	int ans = 0;
	ll nowt = calc1(k1 + 9);
	while (nowt >= k) {
		int t1 = s1[now1] - '0';
		int t2 = s2[now2] - '0';
		if (nowt == k) 
			ans = (t1 + t2 + over) % 10;
		if (t1 + t2 + over >= 10) over = 1;
		else over = 0;
		nowt --;
		now1 --;
		now2 --;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
