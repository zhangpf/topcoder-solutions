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

class BenfordsLaw {
public:
	int questionableDigit(vector <int>, int);
};

int BenfordsLaw::questionableDigit(vector <int> t, int s) {
	vector<int> acc(10);
	for (int i = 0; i < t.size(); i ++) {
		int k = t[i], s = 0;
		while (k) {
			s = k % 10;
			k /= 10;
		}
		acc[s] ++;
	}
	int ans = -1;
	for (int i = 1; ans == -1 && i < 10; i ++) {
		double e = log(1 + 1.0 / i) / log(10.0) * t.size();
		//printf("%d %lf\n", acc[i], e);
		if (e * s < acc[i] || e > acc[i] * s) {
			ans = i;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
