#line 5 "Time.cpp"
#include <string>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

class Time {
	public:
	string whatTime(int seconds) {
		//string ans = "";
		return to_string(seconds / 3600) + ":" \
			+ to_string(seconds % 3600 / 60) + ":" \
				+ to_string(seconds % 60);
	}
};

// Powered by FileEdit
