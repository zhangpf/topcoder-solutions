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
const int maxn = 260;

class RandomPancakeStackDiv2 {
	int n;
	double r[maxn][maxn];
	double t[maxn];
	double calc(int x, int y) {
		if (r[x][y] > -0.5)
			return r[x][y];
		double z = 0;
		if (x == 1) return r[x][y] = t[y];
		for (int i = y - 1; i >= 0; i --) {
			z += calc(x - 1, i);
		}
		r[x][y] = z / (x - 1) + t[y];
		//printf("%d %d %lf\n", x, y, r[x][y]);
		return r[x][y];
	}
public:
	double expectedDeliciousness(vector <int>);
};

double RandomPancakeStackDiv2::expectedDeliciousness(vector <int> d) {
	n = d.size();
	//printf("%d\n", n);
	double ret = 0;
	for (int i = 0; i <= n; i ++) 
		for (int j = 0; j <= n; j ++) 
			r[i][j] = -1;
	for (int i = 0; i < n; i ++) 
		t[i] = d[i];
	for (int i = 0; i < n; i ++) ret += calc(n, i);
	return ret / n;
}
//Powered by [KawigiEdit] 2.0!
