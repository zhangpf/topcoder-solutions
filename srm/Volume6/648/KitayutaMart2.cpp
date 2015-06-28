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

class KitayutaMart2 {
public:
	int numBought(int, int);
};

int KitayutaMart2::numBought(int K, int T) {
	int now = 0, nowP = K, sum = 0;
	while (sum < T) {
		sum += nowP;
		now ++;
		nowP *= 2;
	}
	return now;
}

//Powered by [KawigiEdit] 2.0!
