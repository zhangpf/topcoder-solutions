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
const int INF = 0x3fff;

class PaperFold {
	int calc(int s, int t) {
		int ans = 0;
		while (s > t) {
			s = (s + 1) / 2;
			ans ++;
		}
		return ans;
	}
	
public:
	int numFolds(vector <int>, vector <int>);
};

int PaperFold::numFolds(vector <int> paper, vector <int> box) {
	int x1 = paper[0], y1 = paper[1];
	int x2 = box[0], y2 = box[1];
	int ret = INF;
	ret = min(ret, calc(x1, x2) + calc(y1, y2));
	ret = min(ret, calc(x1, y2) + calc(y1, x2));
	return (ret >= 9) ? -1 : ret;
}
//Powered by [KawigiEdit] 2.0!
