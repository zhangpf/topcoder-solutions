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
#include <cstring>
#include <memory>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 50;

class XorSequenceEasy {
	int nxt[maxn * 32][2], v[maxn * 32][2];
	int num, n;
	int cnt[32][2];
	void update(int x) {
		int now = 0;
		for (int i = n - 1; i >= 0; i --) {
			int ch = 0;
			if ((1 << i) & x) ch = 1;
			if (nxt[now][ch] == -1) {
				nxt[now][ch] = ++num;
				v[now][ch] = 1;
			} else v[now][ch] ++;
			cnt[i][ch] += v[now][ch ^ 1];
			now = nxt[now][ch];
		}
	} 
public:
	long long getmax(vector<int>, int);
};

long long XorSequenceEasy::getmax(vector<int> A, int N) {
	n = 0;
	num = 0;
	memset(nxt, 0xff, sizeof(nxt));
	memset(cnt, 0, sizeof(cnt));
	memset(v, 0, sizeof(v));
	while ((1 << n) < N) n ++; 
	for (int i = 0; i < A.size(); i ++) update(A[i]);
	int ans = 0;
	for (int i = n - 1; i >= 0; i --) {
		ans += max(cnt[i][0], cnt[i][1]);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
