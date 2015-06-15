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
#include <memory>
#include <cstring>

using namespace std;

class StampPads {
	string y[100];
	int ct[1 << 20];
	int ans[1 << 20];
	int m, n;
	int lowbit(int x) {
		return x & (-x);
	}
	int cnt(int x) {
		if (ct[x] != -1) 
			return ct[x];
		int k = lowbit(x);
		if (k == 0) return ct[x] = 0;
		if (k == x) return ct[x] = 1;
		return ct[x] = cnt(x - k) + cnt(k);
	}
	int makebits(string x) {
		stringstream sin(x);
		string s;
		int ret = 0;
		while (sin >> s) {
			for (int j = 0; j < m; j ++) {
				if (y[j] == s) {
					ret |= (1 << j);
					break;
				}
			}
		}
		return ret;
	}
	int calc(int x) {
		int now = 1, ret = 0;
		while (now < x) {
			now <<= 1;
			ret ++;
		}
		return ret;
	}
	
public:
	int bestCombo(vector <string>, vector <string>);
};

int StampPads::bestCombo(vector <string> pads, vector <string> wishlist) {
	n = pads.size();
	m = wishlist.size();
	for (int i = 0; i < m; i ++) y[i] = wishlist[i];
	memset(ct, 0xff, sizeof(ct));
	int ret = 0x3fffffff;
	for (int i = 0; i < (1 << n); i ++) {
		int k = lowbit(i);
		if (k == 0) ans[i] = 0;
		else if (k == i) ans[i] = makebits(pads[calc(i)]);
		else ans[i] = ans[k] | ans[i - k];
		if (ans[i] + 1 == (1 << m)) {
			ret = min(ret, cnt(i));
		}
	}
	return ret != 0x3fffffff ? ret : -1;
}

//Powered by [KawigiEdit] 2.0!
