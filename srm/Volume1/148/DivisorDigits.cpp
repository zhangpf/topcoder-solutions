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

class DivisorDigits {
public:
	int howMany(int);
};

int DivisorDigits::howMany(int numbers) {
	int k = numbers, res = 0;
	do {
		int t = k % 10;
		if (t && numbers % t == 0) res ++;
		k /= 10;
	} while(k);
	return res;
}

//Powered by [KawigiEdit] 2.0!
