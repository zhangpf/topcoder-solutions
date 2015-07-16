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
const double eps = 1e-8;
int dcmp(double x) {
	if (x < -eps) return -1;
	return x > eps;
}

class TickTick {
	int toInt(double x) {
		if (dcmp(x) <= 0) return -1;
		return (int)(floor(x + eps));
	}
public:
	int count(vector <string>);
};

int TickTick::count(vector <string> e) {
	int n = e.size();
	vector<double> r(n); 
	vector<double> s(n + 2);
	s[n] = 0; s[n + 1] = 1;
	for (int i = 0; i < n; i ++) {
		stringstream sin(e[i]);
		sin >> r[i];
		s[i] = r[i] - (int) r[i]; 
	}
	sort(s.begin(), s.end());
	set<string> ans;
	for (int i = 0; i <= n; i ++) {
		double b = (s[i] + s[i + 1]) / 2;
		int now = 0;
		string ret = "";
		for (int j = 0; j < n; j ++) {
			int k = toInt(r[j] - b) + 1;
			if (k == now) ret += 'S';
			else ret += 'D';
			now = k;
		}
	//	cout << ret << endl;
		ans.insert(ret);
	}
	return ans.size();
}

//Powered by [KawigiEdit] 2.0!
