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

class GuessTheNumber {
public:
	int noGuesses(int, int);
};

int GuessTheNumber::noGuesses(int high, int ans) {
	int low = 1, ct = 0;
	while (1) {
		ct ++;
		int mid = (low + high) >> 1;
		if (mid == ans) break;
		else if(mid > ans) high = mid - 1;
		else low = mid + 1;
	}
	return ct;
}

//Powered by [KawigiEdit] 2.0!
