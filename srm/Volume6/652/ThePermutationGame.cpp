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
const int MOD = 1000000007;

class ThePermutationGame {
	int prime[100010], num;
public:
	int findMin(int);
};

int ThePermutationGame::findMin(int N) {
	long long ans = 1;
	num = 0;
	for (int i = 2; i <= N; i ++) {
		int ok = 1;
		for (int j = 0; ok && j < num && prime[j] * prime[j] <= i; j ++) if (i % prime[j] == 0) {
			ok = 0;
		}
		if (ok) {
			prime[num ++] = i;
			long long k = i;
			while (k * i <= N) k *= i;
			ans = ans * k % MOD;
		}
	}
	return (int) ans;
}

//Powered by [KawigiEdit] 2.0!
