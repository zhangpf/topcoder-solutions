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

class InterestingDigits {
	int check(int x, int y) {
		for (int i = 0; i < y; i ++) {
			for (int j = 0; j < y; j ++) {
				for (int k = 0; k < y; k ++) {
					if ((i + j + k) % x == 0 && (i * y * y + j * y + k) % x) return 0;
					if ((i + j + k) % x && (i * y * y + j * y + k) % x == 0) return 0;
				}
			}
		}
		return 1;
	}
public:
	vector <int> digits(int);
};

vector <int> InterestingDigits::digits(int b) {
	vector<int> ans;
	for (int i = 2; i < b; i ++) {
		if (check(i, b)) ans.push_back(i);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
