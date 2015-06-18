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

class StringTrain {
	int check(string s1, string s2, int len) {
		int total = s1.length();
		for (int i = 0; i < len; i ++) {
			if (s1[total - len + i] != s2[i]) return 0;
		}
		return 1;
	}
public:
	string buildTrain(vector <string>);
};

string StringTrain::buildTrain(vector <string> cars) {
	string ans = cars[0];
	for (int i = 1; i < cars.size(); i ++) {
		int len = 0;
		for (int j = cars[i].length() - 1; j >= 1; j --) {
			if (j < ans.length() && check(ans, cars[i], j)) {
				len = j; 
				break;
			}
		}
		if (!len) continue;
		ans += cars[i].substr(len, cars[i].length() - len);
	}
	int total = ans.length();
	set<char> c;
	string ret = "";
	for (int i = total - 1; i >= 0; i --) {
		if (c.find(ans[i]) == c.end()) {
			ret += ans[i];
			c.insert(ans[i]);
		}
	}
	reverse(ret.begin(), ret.end());
	ret = to_string(total) + " " + ret;
	return ret;
}

//Powered by [KawigiEdit] 2.0!
