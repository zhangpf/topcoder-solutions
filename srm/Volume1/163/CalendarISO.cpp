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

class CalendarISO {
	int days(int x) {
		return (x % 4) || (x % 100 == 0 && x % 400) ? 365 : 366; 
	}
	void nextD(int &y, int x1, int y1, int &x2, int &y2) {
		if (x1 == 1 || x1 == 3 || x1 == 5 || x1 == 7 || x1 == 8 || x1 == 10 || x1 == 12) {
			if (y1 == 31) {
				x2 = x1 + 1;
				y2 = 1;
				if (x1 == 12) {
					y = y + 1;
					//x2 = 1;
				}
				return;
			}
		} else if (x1 == 4 || x1 == 6 || x1 == 9 || x1 == 11) {
			if (y1 == 30) {
				x2 = x1 + 1;
				y2 = 1;
				return;
			}
		} else if (x1 == 2) {
			if (days(y) == 365 && y1 == 28) {
				x2 = x1 + 1;
				y2 = 1;
				return;
			} else if (days(y) == 366 && y1 == 29) {
				x2 = x1 + 1;
				y2 = 1;
				return;
			}
		}
		x2 = x1;
		y2 = y1 + 1;
	}
	int calc(int y, int m, int d, int w) {
		int nowM = 1, nowD = 1, ans = 0;
		if (w <= 3) ans ++;
		while (nowM != m || nowD != d) {
			if (w == 6) ans ++;
			w = (w + 1) % 7;
			nextD(y, nowM, nowD, nowM, nowD);
		}
		int oldY = y;
		while (w < 3) {
			w = (w + 1) % 7;
			nextD(y, nowM, nowD, nowM, nowD);
		}
		
		if (oldY != y) ans = 1;
		return ans;
	}
public:
	int weekNumber(int, int, int);
};

int CalendarISO::weekNumber(int y, int m, int d) {
	int now = 2015, offset = 0;
	for (; now < y; now ++) {
		offset += days(now);
	} 
	for (; now > y; now --) {
		offset -= days(now - 1);
	}
	int w = (offset % 7 + 13) % 7;
	int ret = calc(y, m, d, w);
	if (ret == 0) {
		w = (w - days(y - 1) % 7 + 7) % 7;
		ret = calc(y - 1, 13, d, w);
	}
	return ret;
}

//Powered by [KawigiEdit] 2.0!