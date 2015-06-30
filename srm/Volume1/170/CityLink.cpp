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

class CityLink {
	int pnt[60];
	
	int getP(int x) {
		if (x == pnt[x]) return x;
		return pnt[x] = getP(pnt[x]);
	}
	
	int check(vector<int> &x, vector<int> &y, int dis) {
		int n = x.size();
		for (int i = 0; i < n; i ++) pnt[i] = i;
		for (int i = 0; i < n; i ++) {
			for (int j = i + 1; j < n; j ++) {
				int tx = abs(x[i] - x[j]);
				int ty = abs(y[i] - y[j]);
				if (tx == 0 && ty <= dis + dis) pnt[getP(i)] = getP(j);
				else if (ty == 0 && tx <= dis + dis) pnt[getP(i)] = getP(j);
				else if (dis >= tx && dis >= ty) pnt[getP(i)] = getP(j);
			}
		}
		for (int i = 0; i < n; i ++) if (getP(i) != getP(0)) return 0;
		//printf("%d\n", dis);
		return 1;
	}
public:
	int timeTaken(vector <int>, vector <int>);
};

int CityLink::timeTaken(vector <int> x, vector <int> y) {
	int low = 0, high = 0x3ffffff;
	while (low < high) {
		int mid = (low + high) >> 1;
		if (check(x, y, mid)) high = mid;
		else low = mid + 1;
	}
	return low;
}
//Powered by [KawigiEdit] 2.0!
