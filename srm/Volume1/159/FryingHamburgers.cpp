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

class FryingHamburgers {
public:
	int howLong(int, int);
};

int FryingHamburgers::howLong(int p, int h) {
	if (h == 0) return 0;
	else if (p >= h) return 10;
	else return (h + h + p - 1) / p * 5;
}

//Powered by [KawigiEdit] 2.0!
