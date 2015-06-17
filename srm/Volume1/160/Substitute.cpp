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

class Substitute {
public:
	int getValue(string, string);
};

int Substitute::getValue(string key, string code) {
	int ret = 0;
	for (int i = 0; i < code.length(); i ++) {
		
		for (int j = 0; j < key.length(); j ++) if (key[j] == code[i]) {
			ret = ret * 10 + (j + 1) % 10;
		}
	}
	return ret;
}

//Powered by [KawigiEdit] 2.0!
