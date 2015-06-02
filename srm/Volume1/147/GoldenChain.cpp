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

class GoldenChain {
public:
	int minCuts(vector <int>);
};

int GoldenChain::minCuts(vector <int> sections) {
	int n = sections.size();
	sort(sections.begin(), sections.end());
	int sum = 0, now = 0;
	for (int i = 0; i < n; i ++) {
		if (sections[i] + sum > (n - i - 1)) {
			now = i; break;
		} else sum += sections[i];
	}
	return sections.size() - now;
}
//Powered by [KawigiEdit] 2.0!
