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
#include <queue>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 60;

class UndergroundVault {
	vector<list<int> > update(vector<list<int> > g, int x) {
		vector<list<int> > ng(g.size());
		for (int i = 0; i < g.size(); i ++) if (i != x) {
			for (int it: g[i]) if(it != x) ng[i].push_back(it);
		}
		return ng;
	}
	int check(vector<list<int> > g, int y, vector<int> mk) {
		queue<int> q;
		q.push(0);
		vector<int> s(g.size());
		s[0] = 1;
		while (!q.empty()) {
			int x = q.front();
			s[x] = 1;
			q.pop();
			for (int it: g[x]) {
				if (s[it] || it == y) continue;
				q.push(it);
			}
		}
		for (int i = 0; i < g.size(); i ++) if(!mk[i] && !s[i] && (i != y)) return 0;
		return 1;
	}
public:
	vector <int> sealOrder(vector <string>);
};

vector <int> UndergroundVault::sealOrder(vector <string> r) {
	vector<list<int> > g;
	int n = r.size();
	g.resize(n);
	for (int i = 0; i < n; i ++) {
		stringstream sin(r[i]);
		int x; char c;
		while (sin >> x) {
			sin >> c; g[i].push_back(x);
		}
	}
	vector<int> mk(n);
	vector<int> ans;
	for (int i = 1; i < n; i ++) {
		for (int j = 1; j < n; j ++) if (!mk[j] && check(g, j, mk)) {
			mk[j] = 1; 
			ans.push_back(j);
			g = update(g, j);
			break;
		}
	}
	ans.push_back(0);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
