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

class Decipherability {
public:
	string check(string, int);
};

string Decipherability::check(string s, int K) {
	map<char, int> f;
	if (K >= s.length()) return "Certain";
	for (int i = 0; i < s.length(); i++) {
		if (f.find(s[i]) != f.end()) {
			if (K >= i - f[s[i]]) return "Uncertain";
		}
		f[s[i]] = i;
	}
	return "Certain";
}

//Powered by [KawigiEdit] 2.0!
