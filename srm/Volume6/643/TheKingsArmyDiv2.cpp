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

class TheKingsArmyDiv2 {
public:
	int getNumber(vector <string>);
};

int TheKingsArmyDiv2::getNumber(vector <string> s) {
	int found = 0, n = s.size(), m = s[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) if (s[i][j] == 'H') {
			found = 1;
			if (i < n - 1 && s[i + 1][j] == 'H') return 0;
			if (j < m - 1 && s[i][j + 1] == 'H') return 0;
		}
	}
	return 2 - found;
}

//Powered by [KawigiEdit] 2.0!
