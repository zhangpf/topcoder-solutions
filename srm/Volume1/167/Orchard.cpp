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

class Orchard {
public:
	vector <int> nextTree(vector <string>);
};

const int INF = 0x3fffffff;

vector <int> Orchard::nextTree(vector <string> b) {
	int ansX = 0, ansY = 0, minV = -INF;
	int n = b.size();
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) if (b[i][j] != 'T') {
		int nowV = INF;
		nowV = min(nowV, i + 1);
		nowV = min(nowV, j + 1);
		nowV = min(nowV, n - i);
		nowV = min(nowV, n - j);
		for (int u = 0; u < n; u ++) for (int v = 0; v < n; v ++) if(b[u][v] == 'T') {
			nowV = min(nowV, abs(u - i) + abs(j - v));
		}
		if (nowV > minV) {
			minV = nowV;
			ansX = i;
			ansY = j;
		}
	}
	vector<int> ans;
	ans.push_back(ansX + 1);
	ans.push_back(ansY + 1);
	return ans;
}

//Powered by [KawigiEdit] 2.0!
