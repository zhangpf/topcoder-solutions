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

class ProbabilityTree {
	vector<list<int> > tree;
	vector<pair<int, int> > v;
	vector<double> p;
	void dfs(int x, int pnt) {
		if (x) {
			p[x] = ((1 - p[pnt]) * v[x].second + p[pnt] * v[x].first) / 100;
		}
		for (int v: tree[x]) {
			if (pnt == v) continue;
			dfs(v, x);
		}
		p[x] *= 100;
	}
public:
	vector <int> getOdds(vector <string>, int, int);
};

vector <int> ProbabilityTree::getOdds(vector <string> T, int low, int high) {
	int n = T.size();
	tree.resize(n);
	v.resize(n);
	p.resize(n);
	for (int i = 0; i < n; i ++) {
		stringstream sin(T[i]);
		if (!i) {
			sin >> p[0];
			p[0] /= 100;
		} else {
			int parent, ch1, ch2;
			sin >> parent >> ch1 >> ch2;
			tree[parent].push_back(i);
			v[i] = make_pair(ch1, ch2);
		}
	}
	dfs(0, -1);
	vector<int> ans;
	for (int i = 0; i < n; i ++) if (p[i] > low && p[i] < high) ans.push_back(i);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
