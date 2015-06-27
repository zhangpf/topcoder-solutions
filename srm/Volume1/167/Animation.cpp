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

class Animation {
public:
	vector <string> animate(int, string);
};

vector <string> Animation::animate(int speed, string init) {
	vector<string> ans;
	vector<pair<int, int> > p;
	int n = init.size();
	for (int i = 0; i < n; i ++) if (init[i] != '.') {
		p.push_back(make_pair(i, init[i] == 'L' ? 0 : 1));
	}
	int mk = 1;
	while (mk) {
		string now(n, '.');
		mk = 0;
		for (int i = 0; i < p.size(); i ++) {
			if (p[i].first < 0 || p[i].first >= n) continue;
			mk = 1;
			now[p[i].first] = 'X';
			if (p[i].second) p[i].first += speed;
			else p[i].first -= speed;
		}
		ans.push_back(now);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
