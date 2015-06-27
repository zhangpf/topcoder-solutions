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

class TeamPhoto {
	int max(int a, int b, int c) { return std::max(a, std::max(b, c)); }
	int min(int a, int b, int c) { return std::min(a, std::min(b, c)); }
	int p1, p2, p0, n;
	vector<int> h;
	int calc(int x, int y1, int y2, int s1, int s2) {
		int ans = 0x3fffffff;
		int max1, max2, min1, min2;
		for (int i = 0; i < n - s1 + 1; i ++) {
			max1 = max(x, y1, h[i + s1 - 1]);
			min1 = min(x, y1, h[i]);
			if (s2 == 0) max2 = 0;
			else max2 = max(x, y2, (i != n - s1) ? h[n - 1] : h[s2 - 1]);
			if (s2 == 0) min2 = 0;
			else min2 = min(x, y2, (i == 0) ? h[s1] : h[0]);
			ans = std::min(ans, 2 * (max2 + max1 - min1 - min2) - abs(x - y1) - abs(x - y2));
		}
		for (int i = 0; i < n - s2 + 1; i ++) {
			max2 = max(x, y2, h[i + s2 - 1]);
			min2 = min(x, y2, h[i]);
			if (s1 == 0) max1 = 0;
			else max1 = max(x, y1, (i != n - s2) ? h[n - 1] : h[s1 - 1]);
			if (s1 == 0) min1 = 0;
			else min1 = min(x, y1, (i == 0) ? h[s2] : h[0]);
			ans = std::min(ans, 2 * (max2 + max1 - min1 - min2) - abs(x - y1) - abs(x - y2));
		}
		return ans;
	}
public:
	int minDiff(vector <int>);
};

int TeamPhoto::minDiff(vector <int> H) {
	for (int i = 0; i < H.size() - 3; i ++) h.push_back(H[i + 3]);
	n = h.size();
	p0 = H[0], p1 = H[1], p2 = H[2];
	sort(h.begin(), h.end());
	return std::min(calc(p0, p1, p2, n / 2, (n + 1) / 2), calc(p0, p2, p1, n / 2, (n + 1) / 2));
}

//Powered by [KawigiEdit] 2.0!
