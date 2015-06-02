// BEGIN CUT HERE

// END CUT HERE
#line 5 "Roundabout.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Roundabout {
	int convert(char c) {
		if (c == 'N') return 0;
		if (c == 'E') return 1;
		if (c == 'S') return 2;
		return 3;
	}
	int done() {
		int ret = 1;
		for (int i = 0; ret && i < 4; i ++) if (p[i] != -1) ret = 0;
		
		for (int i = 0; ret && i < 4; i ++) {
			for (int j = s[i]; ret && j < c[i].length(); j ++) if (c[i][j] != '-' ) ret = 0;
		}
		return ret;
	}
	int ans = 0, s[4] = {0};
	string c[4];
	int p[4] = {-1, -1, -1, -1}, nxt[4], be[4];
 	public:
	int clearUpTime(string north, string east, string south, string west) {
		c[0] = north;
		c[1] = east;
		c[2] = south;
		c[3] = west;
		while (!done()) {
			//for (int i = 0; i < 4; i++) printf("%d ", p[i]); puts("");
			for (int i = 0; i < 4; i++) {
				be[i] = p[i];
				if (p[i] == i) nxt[i] = -1;
				else nxt[i] = p[i];
			}
			for (int i = 0; i < 4; i++) {
				p[i] = nxt[(i+1)%4];
			}
			
			int mk[4] = {0};
			for (int i = 0; i < 4; i++) {
				while (s[i] <= ans && s[i] < c[i].length() && c[i][s[i]] == '-') s[i] ++;
				if (s[i] > ans || s[i] >= c[i].length()) continue;
				//if (be[(i+1)%4] != -1) mk2[i] = 1;
				//printf("%d %d\n", i, s[i]);
				mk[i] = 1;
			}
			if (mk[0] && mk[1] && mk[2] && mk[3] && be[1] == -1) {
				p[0] = convert(c[0][s[0]]);
				s[0] ++;
			} else {
				//printf("%d %d %d ")
				for (int i = 0; i < 4; i ++) {
					if (mk[i] && mk[(i+1)%4] == 0 && be[(i+1)%4] == -1) {
						p[i] = convert(c[i][s[i]]);
						s[i] ++;
					}
				}
			}
			ans ++;
		}
		return ans;
	}
};
