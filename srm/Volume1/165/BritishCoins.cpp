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

class BritishCoins {
public:
	vector <int> coins(int);
};

vector <int> BritishCoins::coins(int pence) {
	vector<int> ans;
	ans.push_back(pence / 240);
	ans.push_back(pence % 240 / 12);
	ans.push_back(pence % 12);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
