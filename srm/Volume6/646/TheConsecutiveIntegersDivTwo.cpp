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

class TheConsecutiveIntegersDivTwo {
public:
	int find(vector <int>, int);
};

int TheConsecutiveIntegersDivTwo::find(vector <int> numbers, int k) {
	if (k == 1) return 0;
	int n = numbers.size();
	int ans = 0x3fffffff;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) if (numbers[i] < numbers[j]) {
			ans = min(ans, numbers[j] - (numbers[i] + 1));
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
