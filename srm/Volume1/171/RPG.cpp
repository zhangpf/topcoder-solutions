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

class RPG {
public:
	vector <int> dieRolls(vector <string>);
};

vector <int> RPG::dieRolls(vector <string> dice) {
	int t1 = 0, t2 = 0, t3 = 0;
	for(int i = 0; i < dice.size(); i ++) {
		stringstream sin(dice[i]);
		char c; int x, y;
		sin >> x >> c >> y;
		t1 += x;
		t2 += x * y;
		t3 += (1 + y) * x;
	}
	vector<int> ans;
	ans.push_back(t1);
	ans.push_back(t2);
	ans.push_back(t3 / 2);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
