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
const int maxn = 110;

class ThePriceIsRight {
	int n;
	int v[maxn], ct[maxn];
public:
	vector <int> howManyReveals(vector <int>);
};

vector <int> ThePriceIsRight::howManyReveals(vector <int> p) {
	n = p.size();
	for (int i = 0; i < n; i ++) {
		v[i] = 1; ct[i] = 1;
		for (int j = 0; j < i; j ++) {
			if (p[j] < p[i]) {
				if (v[i] == v[j] + 1) ct[i] += ct[j];
				else if (v[i] < v[j] + 1) {
					v[i] = v[j] + 1;
					ct[i] = ct[j];
				}
			}
		}
	}
	int maxV = 0, sum = 0;
	for (int i = 0; i < n; i ++) {
		if (maxV < v[i]) {
			maxV = v[i]; sum = ct[i];
		} else if (maxV == v[i]) {
			sum += ct[i];
		}
	}
	vector<int> ans;
	ans.push_back(maxV);
	ans.push_back(sum);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
