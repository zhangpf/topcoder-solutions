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

class SuperRot {
	char decode(char c) {
		if (c >= 'A' && c <= 'M') return c + 13;
		if (c >= 'N' && c <= 'Z') return c - 13;
		if (c >= 'a' && c <= 'm') return c + 13;
		if (c >= 'n' && c <= 'z') return c - 13;
		if (c >= '0' && c <= '4') return c + 5;
		if (c >= '5' && c <= '9') return c - 5;
		return c;
	}
public:
	string decoder(string);
};

string SuperRot::decoder(string message) {
	string ans = "";
	for (int i = 0; i < message.length(); i ++) {
		ans += decode(message[i]);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
