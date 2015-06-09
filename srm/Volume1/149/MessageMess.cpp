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
const int maxn = 60;

class MessageMess {
	string m;
	vector<string> d;
	string ans[maxn][maxn];
	string calc(int x, int y) {
		if (ans[x][y] != "")
			return ans[x][y];
		ans[x][y] = "IMPOSSIBLE!";
		for (int i = 0; i < d.size(); i ++) {
			if (d[i] == m.substr(x, y - x)) ans[x][y] = d[i];
		}
		for (int i = x + 1; i < y; i ++) {
			string l = calc(x, i);
			string r = calc(i, y);
			if (l == "AMBIGUOUS!") {
				if (r != "IMPOSSIBLE!") return ans[x][y] = "AMBIGUOUS!";
			} else if (l != "IMPOSSIBLE!") {
				if (r == "AMBIGUOUS!") return ans[x][y] = "AMBIGUOUS!";
				if (r != "IMPOSSIBLE!") {
					if (ans[x][y] != "IMPOSSIBLE!" && ans[x][y] != l + " " + r) ans[x][y] = "AMBIGUOUS!";
					else ans[x][y] = l + " " + r;
				}
			}
		}
		return ans[x][y];
	}
public:
	string restore(vector <string>, string);
};

string MessageMess::restore(vector <string> D, string M) {
	d = D;
	m = M;
	return calc(0, M.length());
}

//Powered by [KawigiEdit] 2.0!
