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

class MostProfitable {
public:
	string bestItem(vector <int>, vector <int>, vector <int>, vector <string>);
};

string MostProfitable::bestItem(vector <int> c, vector <int> p, vector <int> s, vector <string> items) {
	int ch = -1;
	for (int i = 0; i < c.size(); i ++) {
		if (ch == -1 || (p[i] - c[i]) * s[i] > (p[ch] - c[ch]) * s[ch]) ch = i;
	}
	if (p[ch] * s[ch] <= c[ch] * s[ch]) return "";
	return items[ch];
}
//Powered by [KawigiEdit] 2.0!
