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

class TireRotation {
	string nextS(string x) {
		string ans = "";
		ans += x[3];
		ans += x[2]; 
		ans += x[0];
		ans += x[1];
		return ans;
	}
public:
	int getCycle(string, string);
};

int TireRotation::getCycle(string initial, string current) {
	int ret = 1;
	string x = initial;
	while (ret <= 4 && x != current) {
		x = nextS(x);
		cout << x;
		ret ++;
	}
	if (ret == 5) ret = -1;
	return ret;
}
//Powered by [KawigiEdit] 2.0!
