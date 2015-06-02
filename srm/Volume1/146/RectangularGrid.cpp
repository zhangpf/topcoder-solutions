// BEGIN CUT HERE

// END CUT HERE
#line 5 "RectangularGrid.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class RectangularGrid {
	public:
	long long countRectangles(int width, int height) {
		long long ans = 0;
		for (int i = 1; i <= width; i ++) {
			for (int j = 1; j <= height; j ++) {
				if (i != j) ans += (width - i + 1) * (height - j + 1);
			}
		}
		return ans;
	}
};
