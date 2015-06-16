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

class CeyKaps {
	int v[26];
public:
	string decipher(string, vector <string>);
};

string CeyKaps::decipher(string typed, vector <string> switches) {
	for (int i = 0; i < 26; i ++) v[i] = i;
	for (int i = 0; i < switches.size(); i ++) {
		int s = switches[i][0] - 'A';
		int t = switches[i][2] - 'A';
		swap(v[s], v[t]);
	}
	for (int i = 0; i < typed.length(); i ++) {
		for (int j = 0; j < 26; j ++) if (v[j] == typed[i] - 'A') {
			typed[i] = j + 'A'; break;
		}
	}
	return typed;
}
//Powered by [KawigiEdit] 2.0!
