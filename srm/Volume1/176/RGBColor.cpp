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

class RGBColor {
	int ok(int x) {
		if (x - (255 - x) > 32 || (255 - x) - x > 32) return 1;
		return 0;
	}
public:
	vector <int> getComplement(vector <int>);
};

vector <int> RGBColor::getComplement(vector <int> rgb) {
	vector<int> ans(3);
	if (ok(rgb[0]) || ok(rgb[1]) || ok(rgb[2])) {
		ans[0] = 255 - rgb[0];
		ans[1] = 255 - rgb[1];
		ans[2] = 255 - rgb[2];
	} else {
		ans[0] = (rgb[0] >= 128) ? (rgb[0] - 128) : (rgb[0] + 128);
		ans[1] = (rgb[1] >= 128) ? (rgb[1] - 128) : (rgb[1] + 128);
		ans[2] = (rgb[2] >= 128) ? (rgb[2] - 128) : (rgb[2] + 128);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
