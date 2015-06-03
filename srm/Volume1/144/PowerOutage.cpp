// BEGIN CUT HERE

// END CUT HERE
#line 5 "PowerOutage.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class PowerOutage {
	int l[50] = {-1};
	public:
	int estimateTimeOut(vector <int> fromJunction, vector <int> toJunction, vector <int> ductLength) {
		int n = fromJunction.size();
		memset(l, 0xff, sizeof(l));
		l[0] = 0;
		int maxV = 0;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				if(l[fromJunction[j]] != -1 && l[toJunction[j]] == -1) {
					l[toJunction[j]] = l[fromJunction[j]] + ductLength[j];
					maxV = max(maxV, l[toJunction[j]]);
				} 
				if(l[toJunction[j]] != -1 && l[fromJunction[j]] == -1) {
					l[fromJunction[j]] = l[toJunction[j]] + ductLength[j];
					maxV = max(maxV, l[fromJunction[j]]);
				} 
			}
		}
		int total = 0;
		for (int i = 0; i < n; i++) total += ductLength[i];
		return total + total - maxV;
	}
};
