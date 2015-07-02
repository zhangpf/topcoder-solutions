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

class PeacefulLine {
public:
	string makeLine(vector <int>);
};

string PeacefulLine::makeLine(vector <int> x) {
	map<int, int> s;
	for (int it: x) s[it] ++;
	for (auto it: s) if (it.second > (x.size() + 1) / 2) return "impossible";
	return "possible";
}

//Powered by [KawigiEdit] 2.0!
