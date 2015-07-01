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

class CrossCountry {
public:
	string scoreMeet(int, string);
};

string CrossCountry::scoreMeet(int n, string s) {
	vector<pair<int, pair<int, int> > > teams(n);
	for (int i = 0; i < s.size(); i ++){
		int x = s[i] - 'A';
		int cnt = teams[x].first + 1;
		int sum = teams[x].second.first;
		int six = teams[x].second.second;
		if (cnt <= 5) sum += (i + 1), six = 0x3ffff;
		if (cnt == 6) {
			six = (i + 1);
		} 
		teams[x] = make_pair(cnt, make_pair(sum, six));
	}
	vector<pair<pair<int, int>, int> > t;
	for (int i = 0; i < n; i ++) {
		if (teams[i].first < 5) continue;
		t.push_back(make_pair(make_pair(
			teams[i].second.first, teams[i].second.second), i));
	}
	sort(t.begin(), t.end());
	string ans = "";
	for (auto it: t) ans += ('A' + it.second);
	return ans;
}
//Powered by [KawigiEdit] 2.0!