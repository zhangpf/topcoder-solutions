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

class Quipu {
public:
	int readKnots(string);
};

int Quipu::readKnots(string s) {
	int res = 0;
	for (int i = 0; i < s.length(); ) {
		if (s[i] == '-') {
			i ++;
			while(i < s.length() && s[i] == s[i - 1]) i++, res = res * 10;
		} else {
			i ++;
			int cnt = 1;
			while(i < s.length() && s[i] == s[i - 1]) i++, cnt ++;
			res = res * 10 + cnt;
		}
	}
	return res;
}
//Powered by [KawigiEdit] 2.0!
