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

class UserId {
	int check(string s, char &c, string &ss) {
		int ans = 0;
		ss = "";
		for (int i = 0; i < s.length(); i ++) {
			if (s[i] >= 'a' && s[i] <= 'z') {
				ans ++;
				if (ans == 1) c = s[i];
				ss += s[i];
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				ans ++;
				if (ans == 1) c = s[i] + 0x20;
				ss += (s[i] + 0x20);
			}
			else if (!(s[i] == '\'' || s[i] == ' ')) return -1; 
		}
		return ans;
	}
	int findStr(const vector <string> &inUse, string &k) {
		if (k.length() > 8) k = k.substr(0, 8);
		for (int i = 0; i < inUse.size(); i++) {
			if (k == inUse[i]) return 1;
		}
		return 0;
	}
public:
	string id(vector <string>, string, string, string);
};

string UserId::id(vector <string> inUse, string first, string middle, string last) {
	char c1, c2, c3;
	string s1, s2, s3;
	int l1 = check(first, c1, s1);
	int l2 = check(middle, c2, s2);
	int l3 = check(last, c3, s3);
	if (l1 == -1 || l2 == -1 || l3 == -1 || l1 < 2 || l3 < 2) return "BAD DATA";
	string ans = "";
	ans += c1;
	ans += s3;
	if (!findStr(inUse, ans)) return ans;
	if (s2 != "" ) {
		ans = "";
		ans += c1;
		ans += c2;
		ans += s3;
		if (!findStr(inUse, ans)) return ans;
	}
	int now = 1;
	while (1) {
		ans = "";
		ans += c1;
		ans += s3;
		if (ans.length() > 6) ans = ans.substr(0, 6);
		if (now < 10) ans += '0';
		ans += to_string(now);
		if (!findStr(inUse, ans)) return ans;
		now ++;
	}
	return "";
}

//Powered by [KawigiEdit] 2.0!
