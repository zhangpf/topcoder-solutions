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

class RecurrenceRelation {
public:
	int moduloTen(vector <int>, vector <int>, int);
};

int RecurrenceRelation::moduloTen(vector <int> c, vector <int> f, int N) {
	int n = c.size();
	if (N < n) return (f[N] % 10 + 10) % 10;
	for (int i = n; i <= N; i ++) {
		int x = 0;
		for (int j = 0; j < n; j ++) x = (x + f[i - n + j] * c[j]) % 10;
		f.push_back((x % 10 + 10) % 10);
	}
	return f[N];
}

//Powered by [KawigiEdit] 2.0!
