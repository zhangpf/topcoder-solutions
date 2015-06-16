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
#include <memory>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int inf = 0x3fffffff;

class TheConsecutiveIntegersDivOne {
	int n;
public:
	int find(vector <int>, int);
};

int TheConsecutiveIntegersDivOne::find(vector <int> numbers, int k) {
	n = numbers.size();
	sort(numbers.begin(), numbers.end());
	int ans = inf;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (i < j || n < k - j + i) continue;
			int sum = 0;
			for (int s = 0; s < k; s ++) {
				sum += abs(numbers[i + s - j] - (numbers[i] + (s - j)));
			}
			ans = min(ans, sum);
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
