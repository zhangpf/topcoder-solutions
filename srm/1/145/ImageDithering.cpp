// BEGIN CUT HERE

// END CUT HERE
#line 5 "ImageDithering.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ImageDithering {
	public:
	int count(string dithered, vector <string> screen) {
		int ans =0;
		for (int i = 0; i < screen.size(); i++) {
			for (int j = 0; j < screen[0].length(); j++) {
				if (dithered.find_first_of(screen[i][j]) != -1) ans ++;
			}
		}
		return ans;
	}
};
