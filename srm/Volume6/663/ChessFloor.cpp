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

class ChessFloor {
public:
	int minimumChanges(vector <string>);
};

int ChessFloor::minimumChanges(vector <string> s) {
	int minV = 100000;
	int n = s.size();
	for (char c1 = 'a'; c1 <= 'z'; c1 ++) {
		for (char c2 = 'a'; c2 <= 'z'; c2 ++) if (c1 != c2) {
			int ans = 0;
			for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) {
				if (((i + j) & 1) && c1 != s[i][j]) ans ++;
				else if(!((i + j) & 1) && c2 != s[i][j]) ans ++;
			}
			minV = min(minV, ans);
		}
	}
	return minV;
}

//Powered by [KawigiEdit] 2.0!
