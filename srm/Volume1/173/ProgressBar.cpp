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

class ProgressBar {
public:
	string showProgress(vector <int>, int);
};

string ProgressBar::showProgress(vector <int> s, int t) {
	int s1 = 0, s2 = 0;
	for (int i = 0; i < s.size(); i ++) {
		s1 += s[i];
		if (i < t) s2 += s[i];
	}
	int ret = s2 * 20 / s1;
	string str1(ret, '#');
	string str2(20 - ret, '.');
	return str1 + str2;
}
//Powered by [KawigiEdit] 2.0!
