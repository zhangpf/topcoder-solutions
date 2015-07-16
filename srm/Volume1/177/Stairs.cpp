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

class Stairs {
public:
	int designs(int, int, int, int);
};

int Stairs::designs(int maxHeight, int minWidth, int totalHeight, int totalWidth) {
	int ans = 0;
	for (int i = 1; i <= totalWidth; i ++) {
		if (totalWidth % i) continue;
		if (totalHeight % (i + 1)) continue;
		int k1 = totalWidth / i;
		int k2 = totalHeight / (i + 1);
		if (k2 <= maxHeight && k1 >= minWidth) ans ++;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
