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
#include <cstring>
#include <memory>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;

const int maxn = 1000010;
class Powerit {
	int a[maxn];
	int p[maxn];
	int b[maxn];
	int num, n, k, m;
	void init() {
		memset(a, 0, sizeof(a));
		num = 0; b[1] = 1;
		for(int i = 2; i < maxn; ++i) {
		   	if (!a[i]) {
				p[num++] = i;
				int now = i, cur = 1;
				for (int j = 0; j < k; j++) {
					cur = ((ll)cur * now) % m;
					now = ((ll)now * now) % m;
				}
				b[i] = cur;
				//printf("%d %d\n", i, b[i]);
			}
			for(int j = 0; (j < num && i*p[j] < maxn && (p[j] <= a[i] || a[i] == 0)); j ++) {
				a[i*p[j]] = p[j];
			}
		}
	}
public:
	int calc(int, int, int);
};

int Powerit::calc(int N, int K, int M) {
	n = N; k = K; m = M;
	init();
	ll ans = 0;	
	for (int i = 1; i <= n; i ++) {
		int now = 1, r = i;
		while (a[r]) {
			//printf("%d\n", a[r]);
			now = ((ll)now * b[a[r]]) % m;
			r = r / a[r];
		}
		ans += ((ll)now * b[r]) % m;
	}
	return ans % m;
	
}
//Powered by [KawigiEdit] 2.0!
