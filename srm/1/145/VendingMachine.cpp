#line 5 "VendingMachine.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <sstream>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class VendingMachine {
	int v[100] = {0}, a[100][100];
	int n, m;
	
	int findMaxC() {
		int maxC = 0;
		for (int i = 0; i < m; i++) if (v[i] > v[maxC]) maxC = i;
		return maxC;
	}
	
	int dis(int x, int y) {
		return min(abs(y-x), m - abs(y-x));
	}
	
	public:
	int motorUse(vector <string> prices, vector <string> purchases) {
		n = prices.size();
		
		for (int i = 0; i < n; i ++) {
			stringstream sin(prices[i]);
			m = 0;
			while(sin>>a[i][m]) {
				m ++;
			}
		}
		
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				v[i] += a[j][i];
			}
		}
		int nowT = 0, nowP = findMaxC(), ret = dis(0, nowP), ok = 1;
		for (int i = 0; ok && i < purchases.size(); i++) {
			int r, c, t;
			char ch;
			stringstream sin(purchases[i]);
			sin >> r >> ch >> c >> ch >> t;
			//cout << r << " " << c << " " << t << endl;
			//r = n - 1 - r;
			if (a[r][c] == 0) ok = 0;
			if (t - nowT >= 5) {
				int tmp = findMaxC();
				ret += (dis(tmp, nowP));
				nowP = tmp;
			}
			ret += dis(c, nowP);
			nowP = c;
			v[c] -= a[r][c];
			a[r][c] = 0;
			nowT = t;
		}
		if (!ok) ret = -1;
		else ret += dis(nowP, findMaxC());
		return ret;
	}
};


// Powered by FileEdit


// Powered by FileEdit
