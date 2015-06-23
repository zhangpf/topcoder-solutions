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

class ParallelSpeedup {
public:
	int numProcessors(int, int);
};

int ParallelSpeedup::numProcessors(int k, int overhead) {
	int ch = -1;
	long long minV = 1LL << 60;
	for (int i = 1; i <= k; i ++) {
		long long ans = (k + i - 1) / i + (long long)i * (i - 1) * overhead / 2;
		if (ans < minV) {
			ch = i;
			minV = ans;
		}
	}
	return ch;
}
//Powered by [KawigiEdit] 2.0!
