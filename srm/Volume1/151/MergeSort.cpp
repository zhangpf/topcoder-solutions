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
const int maxn = 110;

class MergeSort {
	int n;
	int y[maxn], z[maxn];
	int calc(int l, int r) {
		if (r - l <= 1) return 0;
		int mid = (r - l) / 2;
		int ans = calc(l, l + mid) + calc(l + mid, r);
		int b1 = l, b2 = l + mid, now = l;
		while (b1 < l + mid || b2 < r) {
			if (b1 < l + mid && b2 < r) {
				ans ++;
				if (y[b2] < y[b1]) {
					z[now ++] = y[b2 ++];
				} else if (y[b2] > y[b1]) z[now ++] = y[b1 ++];
				else z[now ++] = y[b1 ++], z[now ++] = y[b2 ++];
			} else if (b2 < r) z[now ++] = y[b2 ++];
			else z[now ++] = y[b1 ++];
		}
		for (int i = l; i < r; i++) y[i] = z[i];
		return ans;
	}
public:
	int howManyComparisons(vector <int>);
};

int MergeSort::howManyComparisons(vector <int> x) {
	n = x.size();
	for (int i = 0; i < n; i ++) y[i] = x[i];
	return calc(0, n);
}