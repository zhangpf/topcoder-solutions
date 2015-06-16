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

class MissingLCM {
	int a[1000010];
	int p[1000010];
public:
	int getMin(int);
};

int MissingLCM::getMin(int N) {
	memset(a, 0, sizeof(a));
	int num = 0;
	int ans = N + 1;
	for(int i = 2; i <= N; i ++) {
		if(!(a[i])) {
			p[num++] = i;
			long long now = 1;
			while (now * i<= N) {
				now *= i;
			}
			int k = (N + now) / now;
			ans = max(ans, k * (int)now);
		}
		for(int j = 0; (j < num && i * p[j] <= N); j ++) {
			a[i * p[j]] = 1;
			if(!(i % p[j])) break;
		}
	}
	return ans;
}


//Powered by [KawigiEdit] 2.0!
