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

class CorruptedMessage {
public:
	string reconstructMessage(string, int);
};

string CorruptedMessage::reconstructMessage(string s, int k) {
	string ans;
	for (char c = 'a'; c <= 'z'; c ++) {
		int f = 0;
		ans = "";
		for (int j = 0; j < s.length(); j ++) {
			if (s[j] != c) f ++;
			ans += c;
		}
		if (f <= k) break;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
