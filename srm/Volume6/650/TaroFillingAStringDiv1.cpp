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

const int MOD = 1000000007;
using namespace std;

class TaroFillingAStringDiv1 {
	struct Node {
		int p;
		char v;
	};
	static int cmp(const Node &n1, const Node &n2) {
		return n1.p < n2.p;
	}
	int calc1(int x) {
		return x;
	}
	int calc2(int x) {
		return x;
	}
	vector<Node> s;
public:
	int getNumber(int, vector <int>, string);
};

int TaroFillingAStringDiv1::getNumber(int N, vector <int> p, string v) {
	int n = p.size();
	s.resize(n);
	for (int i = 0; i < n; i ++) {
		s[i].p = p[i]; s[i].v = v[i]; 
	}
	sort(s.begin(), s.end(), cmp);
	long long ans = 1;
	for (int i = 1; i < n; i ++) {
		if (s[i].v == s[i - 1].v && (s[i].p - s[i -1].p) % 2) 
			ans = ans * calc2(s[i].p - s[i - 1].p);
		else if (s[i].v != s[i - 1].v && (s[i].p - s[i -1].p) % 2 == 0)
			ans = ans * calc1(s[i].p - s[i - 1].p);
		ans = ans % MOD; 
	}
	return (int)(ans % MOD);
}

//Powered by [KawigiEdit] 2.0!
