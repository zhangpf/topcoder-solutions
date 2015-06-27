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

class AlphaDice {
	int getV(vector<char> &u, char c,  vector<int> &v) {
		for (int i = 0; i < u.size(); i ++) if (u[i] == c) return v[i];
		return -1;
	}
	int calc(int x1, int x2, int x3, int f1, int f2, int f3) {
		int f[3]; f[0] = f1, f[1] = f2, f[2] = f3;
		if (f[0] == x1 && f[1] == x2 && f[2] == x3) return 1;
		if (f[1] == x1 && f[2] == x2 && f[0] == x3) return 1;
		if (f[2] == x1 && f[0] == x2 && f[1] == x3) return 1;
		return 0;
	}
public:
	int badData(vector <string>);
};

const int f[8][3] = {
	{0, 1, 2},
	{4, 0, 2},
	{5, 4, 2},
	{1, 5, 2},
	{3, 1, 0},
	{3, 0, 4},
	{3, 4, 5},
	{3, 5, 1}
};

int AlphaDice::badData(vector <string> roll) {
	for (int i = 0; i < roll.size(); i ++) {
		set<char> s;
		for (int j = 0; j <= i; j ++) {
			s.insert(roll[j][0]);
			s.insert(roll[j][1]);
			s.insert(roll[j][2]);
		}
		if (s.size() > 6) return i;
		vector<char> u;
		vector<int> v;
		for (int it: s) u.push_back(it);
		for (int j = 0; j < 6; j ++) v.push_back(j);
		int ok = 0;
		do {
			int found = 1;
			for (int j = 0; found && j <= i; j ++) {
				int p1 = getV(u, roll[j][0], v);
				int p2 = getV(u, roll[j][1], v);
				int p3 = getV(u, roll[j][2], v);
				int ok = 0;
				for (int k = 0; !ok && k < 8; k ++) {
					if (calc(p1, p2, p3, f[k][0], f[k][1], f[k][2])) ok = 1;
				}
				if (!ok) found = 0;
			}
			if (found) ok = 1;
		} while(!ok && next_permutation(v.begin(), v.end()));
		if (!ok) return i;
	}
	return -1;
}
//Powered by [KawigiEdit] 2.0!
