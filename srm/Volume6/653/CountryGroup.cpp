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

class CountryGroup {
public:
	int solve(vector <int>);
};

int CountryGroup::solve(vector <int> a) {
	int ans = 0;
	for (int i = 0; i < a.size(); ) {
		int k = a[i];
		for (int j = 0; j < k; j ++) {
			if (j + i >= a.size() || a[j + i] != k) return -1;
		}
		ans ++;
		i += k;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
