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

class SkipRope {
public:
	vector <int> partners(vector <int>, int);
};

vector <int> SkipRope::partners(vector <int> c, int h) {
	vector<pair<int, int> > v;
	for (int i: c) v.push_back(make_pair(abs(i - h), -i));
	sort(v.begin(), v.end());
	vector<int> ans;
	ans.push_back(-v[0].second);
	ans.push_back(-v[1].second);
	if (ans[1] < ans[0]) swap(ans[1], ans[0]);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
