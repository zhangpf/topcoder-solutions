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

class BinaryCardinality {
	static int calc(int x) {
		int ans = 0;
		while (x) {
			if (x & 1) ans ++;
			x >>= 1;
		}
		return ans;
	}
	static int cmp(const int &i, const int &j) {
		int ki = calc(i), kj = calc(j);
		if (ki != kj) return ki < kj;
		return i < j;
	}
public:
	vector <int> arrange(vector <int>);
};

vector <int> BinaryCardinality::arrange(vector <int> numbers) {
	sort(numbers.begin(), numbers.end(), cmp);
	return numbers;
}

//Powered by [KawigiEdit] 2.0!
