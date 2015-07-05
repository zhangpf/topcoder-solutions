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

class OkonomiyakiShop {
public:
	int count(vector <int>, int);
};

int OkonomiyakiShop::count(vector <int> p, int K) {
	sort(p.begin(), p.end());
	int ans = 0;
	for (int i = 0; i < p.size(); i ++) {
		for (int j = i + 1; j < p.size(); j ++) if (p[j] - p[i] <= K) ans ++;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
