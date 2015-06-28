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

class Fragile2 {
	int pnt[30];
	int getP(int x) {
		if (x == pnt[x]) return x;
		return pnt[x] = getP(pnt[x]);
	}
	int calc(vector <string> g, int x, int y) {
		int n = g.size();
		for (int i = 0; i < n; i ++) pnt[i] = i;
		for (int i = 0; i < n; i ++) if (i != x && i != y) {
			for (int j = i + 1; j < n; j ++) if (j != x && j != y && g[i][j] == 'Y') {
				pnt[getP(i)] = getP(j);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; i ++) if (i != x && i != y && getP(i) == i) ans ++;  
		return ans;
	}
public:
	int countPairs(vector <string>);
};

int Fragile2::countPairs(vector <string> graph) {
	int ans = 0;
	int orig = calc(graph, -1, -1);
	for (int i = 0; i < graph.size(); i ++) {
		for (int j = i + 1; j < graph.size(); j ++) {
			if (calc(graph, i, j) > orig) ans ++;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
