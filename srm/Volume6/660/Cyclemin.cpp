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

class Cyclemin {
public:
	string bestmod(string, int);
};

string Cyclemin::bestmod(string s, int k) {
	string ans = s;
	int r = s.length();
	while (r --) {
		s = s.substr(1) + s[0];
		string t = s;
		int op = 0;
		for (int i = 0; i < t.length() && op < k; i ++) {
			if (t[i] != 'a') {
				op ++; 
				t[i] = 'a';
			}
		}
		ans = min(ans, t);
	}
	return ans;
}
