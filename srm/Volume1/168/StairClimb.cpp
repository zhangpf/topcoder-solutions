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

class StairClimb {
public:
	int stridesTaken(vector <int>, int);
};

int StairClimb::stridesTaken(vector <int> f, int s) {
	int ans = 0;
	for (int i = 0; i < f.size(); i ++) ans += (f[i] + s - 1) / s;
	return ans + 2 * f.size() - 2;
}

//Powered by [KawigiEdit] 2.0!
