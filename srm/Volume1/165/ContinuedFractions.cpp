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
#include <cassert>
#include <ctime>

using namespace std;

class ContinuedFractions {
public:
	vector <int> squareRoot(int);
};

vector <int> ContinuedFractions::squareRoot(int x) {
	set<pair<int, int> > c;
	vector<int> ans;
	int c1 = (int)(sqrt(x)), c2 = 1;
	ans.push_back(c1);
	while (1) {
		printf("%d %d\n", c1, c2);
		if (c.find(make_pair(c1, c2)) != c.end())
			break;
		c.insert(make_pair(c1, c2));
		c2 = (x - c1 * c1) / c2;
		c1 = -c1;
		int now = 0;
		while (c1 <= 0 || c1 * c1 < x) c1 += c2, now ++;
		c1 -= c2;
		ans.push_back(now - 1);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
