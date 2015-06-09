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
const double EPS = 1e-9;

class GForce {
	int n, p;
	int x[110], y[110];
	double area(double l) {
		double r = l + p;
		double sum = 0;
		for (int i = 0; i < n - 1; i ++) {
			if (x[i] > l + EPS) break;
			double s = min(l, (double)x[i + 1]);
			double h = y[i] + (s - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
			sum -= (h + y[i]) * (s - x[i]) / 2;
		}
		for (int i = 0; i < n - 1; i ++) {
			if (x[i] > r + EPS) break;
			double s = min(r, (double)x[i + 1]);
			double h = y[i] + (s - x[i]) / (x[i + 1] - x[i]) * (y[i + 1] - y[i]);
			sum += (h + y[i]) * (s - x[i]) / 2;
		}
		return sum;
	}
	double calc(double l, double r) {
		while (l < r - EPS) {
			double mid1 = (l + l + r) / 3;
			double mid2 = (r + r + l) / 3;
			if (area(mid1) > area(mid2)) r = mid2;
			else l = mid1;
		}
		return area(l);
	}	
public:
	double avgAccel(int, vector <int>, vector <int>);
};

double GForce::avgAccel(int P, vector <int> Y, vector <int> X) {
	double ans = 0;
	p = P;
	n = Y.size();
	for (int i = 0; i < n; i ++) x[i] = X[i], y[i] = Y[i];
	for (int i = 0; i < n - 1; i ++) {
		for (int j = i; j < n - 1; j ++) {
			if (x[j + 1] - x[i] >= p && x[j] - x[i + 1] <= p) {
				ans = max(ans, calc(max(x[i], x[j] - p), min(x[j + 1] - p, x[i + 1])));
			}
		}
	}
	return ans / P;
}
//Powered by [KawigiEdit] 2.0!
