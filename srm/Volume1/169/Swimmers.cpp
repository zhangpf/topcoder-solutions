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

class Swimmers {
public:
	vector <int> getSwimTimes(vector <int>, vector <int>, int);
};

vector <int> Swimmers::getSwimTimes(vector <int> d, vector <int> s, int c) {
	vector<int> ans;
	for (int i = 0; i < d.size(); i ++) {
		if (d[i] == 0) ans.push_back(0);
		else if (s[i] <= c) ans.push_back(-1);
		else {
			double dis = d[i];
			int t = (int)(dis / (s[i] - c) + dis / (s[i] + c));
			ans.push_back(t);
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
