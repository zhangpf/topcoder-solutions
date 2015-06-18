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

class CardCount {
public:
	vector <string> dealHands(int, string);
};

vector <string> CardCount::dealHands(int n, string deck) {
	int m = deck.length() / n;
	vector<string> ans(n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			ans[i].push_back(deck[j * n + i]);
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
