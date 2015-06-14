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

class Inventory {
public:
	int monthlyOrder(vector <int>, vector <int>);
};

int Inventory::monthlyOrder(vector <int> s, vector <int> d) {
	double cnt = 0, sum = 0;
	for (int i = 0; i < d.size(); i ++) {
		if (d[i] == 0) continue;
		cnt ++;
		sum += 30.0 * s[i] / d[i];
	}
	if (cnt == 0) return 0;
	return (int)(ceil(sum / cnt - 1e-8));
}

//Powered by [KawigiEdit] 2.0!
