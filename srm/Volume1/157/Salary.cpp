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
#include <memory>
#include <cstring>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Salary {
	int mk[86400];
	void sign(int x, int y) {
		for (int i = x; i < y; i ++) mk[i] = 1;
	}
	int calc(string s) {
		int hh = (s[0] - '0') * 10 + (s[1] - '0');
		int mm = (s[3] - '0') * 10 + (s[4] - '0');
		int ss = (s[6] - '0') * 10 + (s[7] - '0');
		return hh * 3600 + mm * 60 + ss;
	}
public:
	int howMuch(vector <string>, vector <string>, int);
};

int Salary::howMuch(vector <string> S, vector <string> T, int wage) {
	memset(mk, 0, sizeof(mk));
	for (int i = 0; i < S.size(); i ++) {
		int t1 = calc(S[i]);
		int t2 = calc(T[i]);
		sign(t1, t2);
	}
	double sum = 0;
	for (int i = 0; i < 86400; i ++) if (mk[i]) {
		if (i < 21600 || i >= 64800) sum += 1.5;
		else sum += 1;
	}
	return (int)(wage * sum / 3600.0);
}
//Powered by [KawigiEdit] 2.0!
