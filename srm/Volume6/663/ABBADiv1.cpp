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
#include <memory>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 60;

class ABBADiv1 {
	string getS(int x, int y, int k) {
		string ans = s.substr(x, y - x);
		if (k) reverse(ans.begin(), ans.end());
		return ans;
	}
	string s, t;
	int ans[maxn][maxn];
	int n, m;
	int calc(int x, int y, int k) {
		if (ans[x][y] != -1)
			return ans[x][y];
		if (y - x == m) {
			if (getS(x, y, k) == t) return ans[x][y] = 1;
			return ans[x][y] = 0;
		}
		ans[x][y] = 0;
		if (k) {
			if (s[x] == 'A' && calc(x + 1, y, 1)) ans[x][y] = 1;
			else if (s[y - 1] == 'B' && calc(x, y - 1, 0)) ans[x][y] = 1; 
		} else {
			if (s[x] == 'B' && calc(x + 1, y, 1)) ans[x][y] = 1;
			else if (s[y - 1] == 'A' && calc(x, y - 1, 0)) ans[x][y] = 1;
		}
		return ans[x][y];
	}
public:
	string canObtain(string, string);
};

string ABBADiv1::canObtain(string T, string S) {
	s = S; t = T;
	n = S.length();
	m = T.length();
	memset(ans, 0xff, sizeof(ans));
	if (calc(0, n, 0)) return "Possible";
	else return "Impossible";
}

//Powered by [KawigiEdit] 2.0!
