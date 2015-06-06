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
const int maxn = 60;

class OddEvenTree {
	int c[maxn][maxn];
	int pnt[maxn];
	int n;
	int getP(int x) {
		if (pnt[x] == x) return x;
		return pnt[x] = getP(pnt[x]);
	}
public:
	vector <int> getTree(vector <string>);
};

vector <int> OddEvenTree::getTree(vector <string> x) {
	n = x.size();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) c[i][j] = (x[i][j] == 'O');
	}
	int ok = 1;
	for (int i = 0; ok && i < n; i ++) {
		ok = !c[i][i];
		for (int j = 0; ok && j < n; j ++) ok = (c[i][j] == c[j][i]);
		for (int j = 0; ok && j < n; j ++) for (int k = 0; ok && k < n; k ++) {
			ok = (c[i][j] == (c[i][k] ^ c[k][j]));
		}
	}
	vector<int> ans;
	if (ok == 0) {
		ans.push_back(-1);
		return ans;
	}
	for (int i = 0; i < n; i ++) pnt[i] = i;
	for (int i = 1; ok && i < n; i ++) {
		int found = 0;
		for (int j = 0; !found && j < n; j ++) for (int k = 0; !found && k < n; k ++) {
			if (c[i][j] && getP(i) != getP(j)) {
				pnt[getP(i)] = getP(j);
				found = 1;
				ans.push_back(i);
				ans.push_back(j);
			}
		}
		if (found == 0) {
			ok = 0;
			ans.clear();
			ans.push_back(-1);
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
