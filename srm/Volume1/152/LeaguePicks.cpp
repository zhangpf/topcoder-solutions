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

class LeaguePicks {
public:
	vector <int> returnPicks(int, int, int);
};

vector <int> LeaguePicks::returnPicks(int p, int f, int g) {
	vector<int> ans;
	int now = 1, d = 1;
	for (int i = 1; i <= g; i ++) {
		if (now == p) ans.push_back(i);
		if (d == 1 && now == f) {
			d = -1;
		} else if (d == -1 && now == 1) {
			d = 1;
		} else now += d;
 	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
