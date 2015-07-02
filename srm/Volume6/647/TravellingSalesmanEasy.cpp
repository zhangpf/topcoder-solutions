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

class TravellingSalesmanEasy {
public:
	int getMaxProfit(int, vector <int>, vector <int>, vector <int>);
};

int TravellingSalesmanEasy::getMaxProfit(int M, vector <int> p, vector <int> city, vector <int> visit) {
	int ans = 0;
	vector<int> mk(city.size());
	for (int i: visit) {
		int maxP = -1;
		for (int j = 0; j < city.size(); j ++) {
			if (city[j] != i || mk[j]) continue;
			if (maxP == -1 || p[maxP] < p[j]) maxP = j;
		}
		if (maxP != -1) {
			mk[maxP] = 1;
			ans += p[maxP];
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
