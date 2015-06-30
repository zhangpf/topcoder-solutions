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

class LevelUp {
public:
	int toNextLevel(vector <int>, int);
};

int LevelUp::toNextLevel(vector <int> s, int t) {
	for (int i = 0; i < s.size(); i ++) if (s[i] > t) return s[i] - t;
	return -1;	
}


//Powered by [KawigiEdit] 2.0!
