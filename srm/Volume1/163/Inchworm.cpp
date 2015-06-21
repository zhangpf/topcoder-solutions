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

class Inchworm {
public:
	int lunchtime(int, int, int);
};

int Inchworm::lunchtime(int branch, int rest, int leaf) {
	int ans = 0;
	for (int i = 0; i <= branch; i += rest) {
		if (i % leaf == 0) ans ++;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
