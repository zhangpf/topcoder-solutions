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

class BaseMystery {
public:
	vector <int> getBase(string);
};

vector <int> BaseMystery::getBase(string s) {
	int n = s.length();
	vector<int> ans;
	for (int i = 2; i <= 20; i ++) {
		int st = 0, ok = 1;
		int s1 = 0, s2 = 0, s3 = 0;
		for (int j = 0; ok && j < n; j ++) {
			if (s[j] == '+') st = 1;
			else if (s[j] == '=') st = 2;
			else {
				int k = 0;
				if (s[j] >= '0' && s[j] <= '9') k = s[j] - '0';
				else k = s[j] - 'A' + 10;
				if (k >= i) ok = 0;
				if (st == 0) s1 = s1 * i + k;
				if (st == 1) s2 = s2 * i + k;
				if (st == 2) s3 = s3 * i + k;
			}
		}
		if (ok && s1 + s2 != s3) ok = 0;
		if (ok) ans.push_back(i);	
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
