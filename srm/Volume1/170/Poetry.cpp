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

class Poetry {
	int vowel(char c, int f) {
		if (c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u') return 1;
		if (f && c == 'y') return 1;
		return 0;
	}
	int rhyme(string s, char l, int pos) {
		if (l && vowel(l, pos != 1)) return 0;
		if (!vowel(s[0], l != 0 && s.length() != 1)) return 0;
		int st = 0;
		for (int i = 0; i < s.length(); i ++) {
			if (st == 0 && !vowel(s[i], (i || l) && i != s.length() - 1)) st = 1;
			else if (st == 1 && vowel(s[i], (i || l) && i != s.length() - 1)) return 0;
		}
		return 1;
	}
	string calc(string s) {
		int sz = s.length();
		while (sz && s[sz - 1] == ' ') sz --;
		if (sz == 0) return "EMPTY";
		s.resize(sz);
		int k = s.rfind(' ');
		string last_k = s, last = "";
		if (k != std::string::npos) last_k = s.substr(k + 1);
		for (auto it: last_k) last += tolower(it);
		for (int i = 0; i < last.length(); i ++) {
			string sub = last.substr(i);
			char c = (i == 0) ? 0 : last[i - 1];
			if (rhyme(sub, c, i)) return sub;
		}
		return "";
	}
	char getIdx(int x) {
		if (x < 26) return x + 'a';
		else return x - 26 + 'A';
	}
public:
	string rhymeScheme(vector <string>);
};

string Poetry::rhymeScheme(vector <string> poem) {
	int n = poem.size();
	vector<string> r(n);
	string ans(n, ' ');
	for (int i = 0; i < n; i ++) {
		string rhyming = calc(poem[i]);
		r[i] = rhyming;
	}
	int now = 0;
	for (int i = 0; i < n; i ++) {
		if (r[i] == "EMPTY") {
			ans[i] = ' ';
			continue;
		} else if (r[i] == "") {
			ans[i] = getIdx(now ++);
			continue;
		}
		int found = 0;
		for (int j = 0; !found && j < i; j ++) if (r[i] == r[j]) {
			ans[i] = ans[j];
			found = 1;
		}
		if (!found) ans[i] = getIdx(now ++);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
