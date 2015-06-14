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

class Collision {
	double calc1(int x, int y) {
		if (x > y) return 0;
		double ans = 1;
		for (int i = 0; i < x; i ++) {
			ans *= (y - i);
			ans /= y;
		}
		return ans;
	}
	double calc2(int x, vector<int> y) {
		double ans = 1;
		int t = x;
		for (int i = 0; i < y.size(); i ++) {
			if (x < y[i]) return 0;
			for (int j = 0; j < y[i]; j ++) {
				//printf ("%d %d\n", t, x - j);
				ans *= t;
				t --;
				ans /= (x - j);
			}
		}
		return ans;
	}
public:
	double probability(vector <int>, int);
};

double Collision::probability(vector <int> a, int ids) {
	int sum = 0;
	for (int i = 0; i < a.size(); i ++) {
		sum += a[i];
	}
	double ans1 = calc1(sum, ids);
	double ans2 = calc2(ids, a);
	//printf("%.20lf\n", ans2 - ans1);
	return ans2 - ans1;
}

//Powered by [KawigiEdit] 2.0!
