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

class Fifteen {
	int check(vector<int> &x) {
		for (int i = x.size() - 1; i >= 0; i --) {
			for (int j = x.size() - 1; j > i; j --) {
				for (int k = x.size() - 1; k > j; k --) if (x[i] + x[j] + x[k] == 15) return 1;
			}
		}
		return 0;
	}
	int dfs(int d, vector<int> x, vector<int> y, vector<int> &mk) {
		if (check(x)) return 1;
		if (check(y)) return 0;
		if (d == 9) return 0;
		vector<int> nx, ny;
		int ret = 0;
		for (int i = 1; i <= 9; i ++) if (!mk[i]) {
			mk[i] = 1;
			nx = x; ny = y;
			if (d & 1) nx.push_back(i);
			else ny.push_back(i);
			int k = dfs(d + 1, nx, ny, mk);
			ret = k;
			mk[i] = 0;
			if ((d & 1) && k) return i;
			else if (!(d & 1) && !k) return 0;
		}
		return ret;
	}
public:
	string outcome(vector <int>);
};

string Fifteen::outcome(vector <int> moves) {
	vector<int> mk(9), x, y;
	for (int i = 0; i < moves.size(); i ++) {
		if (i & 1) x.push_back(moves[i]);
		else y.push_back(moves[i]);
		mk[moves[i]] = 1;
	}
	int k = dfs(moves.size(), x, y, mk);
	if (k) return "WIN " + to_string(k);
	else return "LOSE";
}
//Powered by [KawigiEdit] 2.0!
