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

class ValueOfString {
public:
	int findValue(string);
};

int ValueOfString::findValue(string s) {
	vector<int> cnt(26);
	for (int i = 0; i < s.length(); i ++) cnt[s[i] - 'a'] ++;
	int sum = 0, ret = 0;
	for (int i = 0; i < 26; i ++) {
		sum += cnt[i];
		ret += sum * (i + 1) * cnt[i];
	}
	return ret;
}

//Powered by [KawigiEdit] 2.0!
