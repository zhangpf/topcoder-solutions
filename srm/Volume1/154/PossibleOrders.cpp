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
#include <memory>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
typedef long long ll;

using namespace std;
const int maxn = 20;

class PossibleOrders {
	ll ans[maxn][maxn];
	ll calc (int x, int y) {
		if (ans[x][y] != -1)
			return ans[x][y];
		if (y > x) ans[x][y] = 0;
		else if (y == 0) ans[x][y] = 1;
		else if (x == 1 || y == 1) ans[x][y] = 1;
		else ans[x][y] = calc(x - 1, y) * y + calc(x - 1, y - 1) * y; 
		return ans[x][y];
	}
	int pnt[20];
	int getP(int x) {
		if (pnt[x] == x) return x;
		return pnt[x] = getP(pnt[x]);
	}
public:
	long long howMany(int, vector <string>);
};

long long PossibleOrders::howMany(int num, vector <string> facts) {
	memset(ans, 0xff, sizeof(ans));
	//printf("%lld %lld\n", calc(1, 1), calc(2, 1));
	for (int i = 0; i < num; i ++) pnt[i] = i;
	int cnt = num;
	for (int i = 0; i < facts.size(); i ++) {
		stringstream sin(facts[i]);
		int k1, k2;
		char c;
		sin >> k1 >> c >> k2;
		if (getP(k1) != getP(k2)) {
			pnt[getP(k1)] = getP(k2);
			cnt --;
		}
	}
	ll ans = 0;
	for (int i = 1; i <= cnt; i ++) ans += calc(cnt, i);
	return ans;
}
//Powered by [KawigiEdit] 2.0!
