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

class OddEvenTreeHard {
	int n;
	int pnt[maxn];
	int getP(int x) {
		if (pnt[x] == x) return x;
		return pnt[x] = getP(pnt[x]);
	}
	int c[maxn][maxn];
public:
	vector <int> getTree(vector <string>);
};

vector <int> OddEvenTreeHard::getTree(vector <string> x) {
	n = x.size();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (x[i][j] == 'O') c[i][j] = 1;
			else if (x[i][j] == 'E') c[i][j] = 0;
			else c[i][j] = -1;
		}
	}
	int ok = 1;
	for (int i = 0; ok && i < n; i ++) {
		ok = (c[i][i] != 1);
		if (c[i][i] == -1) c[i][i] = 0;
	}
	for (int i = 0; ok && i < n; i ++) {
		for (int j = 0; ok && j < n; j ++) {
			if (c[i][j] != -1 && c[j][i] != -1) ok = (c[i][j] == c[j][i]);
			else {
				if (c[i][j] == -1) c[i][j] = c[j][i];
				if (c[j][i] == -1) c[j][i] = c[i][j];
			}
		}
	}
	for (int i = 0; ok && i < n; i ++) {
		for (int j = 0; ok && j < n; j ++) for (int k = 0; ok && k < n; k ++) {
			if (c[j][i] != -1 && c[i][k] != -1) {
				if (c[j][k] == -1) c[j][k] = c[j][i] ^ c[i][k];
				else ok = (c[j][k] == (c[j][i] ^ c[i][k]));
			}
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
		for (int j = 0; !found && j < n; j ++) {
			if (c[i][j] == 1 && getP(i) != getP(j)) {
				pnt[getP(i)] = getP(j);
				found = 1;
				ans.push_back(i);
				ans.push_back(j);
			}
		}
		for (int j = 0; !found && j < n; j ++) {
			if (c[i][j] == -1 && getP(i) != getP(j)) {
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
