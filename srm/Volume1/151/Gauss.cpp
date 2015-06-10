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

class Gauss {
	long long n;
	int calc(long long x, long long y, long long &a, long long &b) {
		if (x < 2 || y < 2) return 0;
		if (x > y && ((y - x) & 1)) {
			a = (x - y + 1) / 2;
			b = (x + y - 1) / 2;
			return 1;
		}
		return 0;
	}
public:
	vector <string> whichSums(string);
};

vector <string> Gauss::whichSums(string target) {
	stringstream sin(target);
	sin >> n;
	n = n + n;
	vector<string> ans1, ans2;
	long long a, b;
	for (long long i = 2; i * i <= n; i ++) if (n % i == 0) {
		if (calc(i, n / i, a, b))
			ans1.push_back("[" + to_string(a) + ", " + to_string(b) + "]");
		if (i * i != n && calc(n / i, i, a, b))
			ans2.push_back("[" + to_string(a) + ", " + to_string(b) + "]");
	}
	for (int i = ans2.size() - 1; i >= 0; i --) ans1.push_back(ans2[i]);
	return ans1;
}

//Powered by [KawigiEdit] 2.0!
