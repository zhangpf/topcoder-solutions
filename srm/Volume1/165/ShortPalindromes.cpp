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

class ShortPalindromes {
public:
	string shortest(string);
	string ans[30][30];
	string s;
	int tLen;
	void reset() {
		for (int i = 0; i <= tLen; i ++) {
			for (int j = 0; j <= tLen; j ++) ans[i][j] = "";
		}
	}
	void update(string &x, const string &y) {
		if (x.length() > y.length())
			x = y;
		else if (x.length() == y.length() && x > y)
			x = y;
	}
	string calc(int x, int y) {
		if (x < 0) {
			string ret = s.substr(y);
			reverse(ret.begin(), ret.end());
			return ret;
		}
		if (y >= tLen) return s.substr(0, x + 1);
		if (ans[x][y] != "")
			return ans[x][y];
		ans[x][y] = s + s + s + s;
		if (x >= 0 && y < tLen && s[x] == s[y])
			update(ans[x][y], calc(x - 1, y + 1) + s[x]);
		if (x >= 0)
			update(ans[x][y], calc(x - 1, y) + s[x]);
		if (y < tLen) 
			update(ans[x][y], calc(x, y + 1) + s[y]);
		return ans[x][y];
	}
};

string ShortPalindromes::shortest(string base) {
	int n = base.length();
	string ans;
	s = base;
	tLen = n;
	int len = 0x3ffffff;
	//printf("%d\n", n);
	for (int i = 0; i < n; i ++) {
		int l1 = i - 1, l2 = i + 1;
		reset();
		string now = calc(l1, l2);
		string ret = now + base[i];
		reverse(now.begin(), now.end());
		ret += now;
		//cout << ret << endl;
		if (ret.length() < len || (ret.length() == len && ret < ans)) {
			ans = ret;
			len = ret.length();
		}
	}
	for (int i = 0; i <= n; i ++) {
		int l1 = i - 1, l2 = i;
		reset();
		string now = calc(l1, l2);
		string ret = now;
		reverse(now.begin(), now.end());
		ret += now;
		if (ret.length() < len || (ret.length() == len && ret < ans)) {
			ans = ret;
			len = ret.length();
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
