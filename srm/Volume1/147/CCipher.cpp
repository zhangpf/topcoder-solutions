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

class CCipher {
public:
	string decode(string, int);
};

string CCipher::decode(string s, int shift) {
	for (int i = 0; i < s.length(); i ++) s[i] = (s[i] - 'A' - shift + 26) % 26 + 'A';
	return s;
}

//Powered by [KawigiEdit] 2.0!
