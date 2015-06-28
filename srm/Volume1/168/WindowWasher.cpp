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

class WindowWasher {
public:
	int fastest(int, int, vector <int>);
};

int WindowWasher::fastest(int r, int c, vector <int> w) {
	int low = 1, high = 0x3fffffff;
	while (low < high) {
		int mid = (low + high) >> 1;
		int sum = 0;
		for (int i = 0; i < w.size(); i ++) {
			sum += (mid / c / w[i]);
		}
		if (sum >= r) high = mid;
		else low = mid + 1;
	}
	return low;
}

//Powered by [KawigiEdit] 2.0!
