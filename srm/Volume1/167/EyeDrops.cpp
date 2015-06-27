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

class EyeDrops {
public:
	double closest(int, int);
};

double EyeDrops::closest(int s, int k) {
	return min((24 - s) * 60.0 / (k - 1), 1440.0 / k);
}

//Powered by [KawigiEdit] 2.0!
