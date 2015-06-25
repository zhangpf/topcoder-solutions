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

class CircleBugs {
	map<string, int> s;
	int n;
	string reverse(string st) {
		string newS = "";
		for (int i = st.length() - 1; i >= 0; i --) newS += st[i];
		return newS;
	}
	int find(string st) {
		for (int i = 0; i < n; i ++) {
			if (s.find(st) != s.end()) return s[st];
			if (s.find(reverse(st)) != s.end()) return s[st];
			st = st.substr(1) + st[0];
		}
		return 0;
	}
public:
	int cycleLength(string);
};

int CircleBugs::cycleLength(string st) {
	n = st.length();
	int ans = 0, ret;
	while (1) {
		ans ++;
		s[st] = ans;
 		string newS = "";
		for (int i = 0; i < n; i ++) {
			char nxt = st[0];
			if (i != n - 1) nxt = st[i + 1];
			if (nxt == st[i]) newS += 'R';
			else newS += 'G';
		}
		st = newS;
		if (ret = find(st)) {
			ans = ans - ret + 1;
			break;
		} 
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
