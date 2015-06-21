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

class CalendarRecycle {
	int run(int x) {
		return (x % 4 == 0 && x % 100) || (x % 400 == 0);
	}
public:
	int useAgain(int);
};

int CalendarRecycle::useAgain(int year) {
	int y = year, now = 0;
	do{
		now += (run(y) ? 366 : 365);
		y ++;
	} while (now % 7 || run(year) != run(y));
	return y;
}
