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
#include <memory>
#include <cstring>

using namespace std;

class Privateparty {
	int mk[60];
public:
	double getexp(vector <int>);
};

double Privateparty::getexp(vector <int> a) {
	double ans = 0;
	for (int i = 0; i < a.size(); i++) {
		memset(mk, 0, sizeof(mk));
		int cnt = 0, now = i;
		do {
			mk[now] = 1;
			now = a[now];
			cnt ++;
		} while(!mk[now]);
		double y = 1;
		for (int j = 0; j < cnt; j ++) {
			ans += y; y *= - 1.0 / (j + 2);
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
