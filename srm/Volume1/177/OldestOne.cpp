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

class OldestOne {
	int isDigit(char x) {
		return x >= '0' && x <= '9';
	}
	pair<int, string> calc(string x) {
		int sz = x.length();
		for (int i = 0; i < sz; i ++) {
			for (int j = sz; j > i; j --) {
				int now = i, age = 0, ok = 1;
				while (now < j && ok) {
					if (!isDigit(x[now])) ok = 0;
					else {
						age = age * 10 + (x[now] - '0');
					}
					now ++;
				}
				if (ok) {
					int b = 0, e = i - 1;
					while (x[b] == ' ') b ++;
					while (x[e] == ' ') e --;
					return make_pair(age, x.substr(b, e - b + 1));
				} 
			}
		}
	}
public:
	string oldest(vector <string>);
};

string OldestOne::oldest(vector <string> data) {
	int maxA = 0;
	string ans;
	for (string info: data) {
		pair<int, string> k = calc(info);
		if (k.first > maxA) {
			maxA = k.first;
			ans = k.second;
		}
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
