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

class NumberGuesser {
public:
	int guess(string);
};

int NumberGuesser::guess(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i ++) {
		sum += (s[i] - '0');
	}
	return (9 - sum % 9);
}
//Powered by [KawigiEdit] 2.0!
