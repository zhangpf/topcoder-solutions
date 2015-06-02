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

class PeopleCircle {
	int F, M, K;
	string dfs(int depth, int pos, string now) {
		if (depth == F) {
			if (pos == 0) return now;
			else return "";
		}
		string ret = "";
		now.insert(now.begin() + pos, 'F');
		pos = (pos - K % now.length() + now.length()) % now.length();
		if ((ret = dfs(depth+1, pos, now)) == "" && pos == 0)
			ret = dfs(depth+1, now.length(), now);
		return ret;
	}
public:
	string order(int, int, int);
};

string PeopleCircle::order(int Male, int Female, int KK) {
	M = Male;
	F = Female;
	K = KK - 1;
	string ans = "", ret;
	for (int i = 0; i < M; i++) ans += 'M';
	int found = 0;
	for (int i = 0; !found && i <= M; i++) {
		ret = dfs(0, i, ans);
		if (ret != "") {
			found = 1;
		}
	}
	return ret;
}
//Powered by [KawigiEdit] 2.0!

