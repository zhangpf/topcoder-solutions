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

class PrivateD2party {
	int pnt[maxn], n;
	int getP(int x) {
		if (pnt[x] == x) return x;
		return pnt[x] = getP(pnt[x]);
	}
public:
	int getsz(vector <int>);
};

int PrivateD2party::getsz(vector <int> a) {
	n = a.size();
	for (int i = 0; i < n; i ++) pnt[i] = i;
	int ans = n;
	for (int i = 0; i < n; i ++) { 
		if (i == a[i]) ans ++;
		pnt[getP(a[i])] = getP(i);
	}
	for (int i = 0; i < n; i ++) if (getP(i) == i) {
		ans --;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
