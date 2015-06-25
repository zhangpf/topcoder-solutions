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
#include <cstring>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class TheKingsRoadsDiv1 {
	int d[1030];
	int h, n;
	int q[1030];
	vector<list<int> > graph;
	int dfs (int l, int r) {
		int no = q[l];
		if (l == n) return 1;
		if (l >= r) return 0;
		if (d[no] == h - 1)
			return dfs(l + 1, r);
		set<int> v;
		for (int it: graph[no]) {
			if (d[it] != -1) continue;
			v.insert(it);
		}
		int sz = v.size();
		if (sz < 2 || sz > 5) return 0;
		for (int vi : v) for (int vj: v) if (vi < vj) {
			d[vi] = d[no] + 1;
			d[vj] = d[no] + 1;
			q[r] = vi, q[r + 1] = vj;
			if (dfs(l + 1, r + 2)) return 1;
			d[vi] = d[vj] = -1;
		}
		return 0;
	}
public:
	string getAnswer(int, vector <int>, vector <int>);
};

string TheKingsRoadsDiv1::getAnswer(int H, vector <int> a, vector <int> b) {
	h = H;
	n = (1 << h) - 1;
	graph.resize(n);
	
	for (int i = 0; i < n + 2; i ++) {
		a[i] --; b[i] --;
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	for (int i = 0; i < n; i ++) {
		memset(d, 0xff, sizeof(d));
		q[0] = i; d[i] = 0; 
		if (dfs(0, 1)) return "Correct";
	}
	return "Incorrect";
}

//Powered by [KawigiEdit] 2.0!
