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

class Twain {
	string calc1(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if (s[i] != 'x') ans += s[i];
			else if (i == 0 || s[i - 1] == ' ') ans += 'z';
			else ans += "ks";
		}
		return ans;
	}
	string calc2(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if (s[i] == 'y') ans += 'i';
			else ans += s[i];
		}
		return ans;
	}
	string calc3(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if (s[i] != 'c') ans += s[i];
			else if (i != s.length() - 1 && (s[i + 1] == 'e' || s[i + 1] == 'i')) ans += 's';
			else ans += 'c';
		}
		return ans;	
	}
	string calc4(string s) {
		string ans = "";
		for (int i = s.length() - 1; i >= 0; i --) {
			if (s[i] == 'c' && ans.length() && ans[0] == 'k') continue;
			ans = s[i] + ans;
		}
		return ans;
	}
	string calc5(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if ((i == 0 || s[i - 1] == ' ') && s[i] == 's' && s[i + 1] == 'c' && s[i + 2] == 'h')  {
				ans += "sk"; i += 2;
			} else if (s[i] == 'c' && s[i + 1] == 'h' && s[i + 2] == 'r') {
				ans += 'k'; i ++;
			} else if (s[i] == 'c' && s[i + 1] != 'h') ans += 'k';
			else ans += s[i];
		}
		return ans;
	}
	string calc6(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if ((i == 0 || s[i - 1] == ' ') && s[i] == 'k' && s[i + 1] == 'n')  {
				ans += 'n'; i ++;
			}
			else ans += s[i];
		}
		return ans;
	}
	string calc7(string s) {
		string ans = "";
		for (int i = 0; i < s.length(); i ++) {
			if (ans == "") ans += s[i];
			else if (ans[ans.length() - 1] != s[i]) ans += s[i];
			else if (s[i] != ' ' && s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u') continue;
			else ans += s[i];
		}
		return ans;
	}
	
public:
	string getNewSpelling(int, string);
};

string Twain::getNewSpelling(int year, string s) {
	if (year >= 1) s = calc1(s); 
	if (year >= 2) s = calc2(s);
	if (year >= 3) s = calc3(s);
	if (year >= 4) s = calc4(s);
	if (year >= 5) s = calc5(s);
	if (year >= 6) s = calc6(s);
	if (year >= 7) s = calc7(s);
	return s;
}
//Powered by [KawigiEdit] 2.0!
