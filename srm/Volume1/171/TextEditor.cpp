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

class TextEditor {
public:
	vector <string> twoColumn(vector <string>, int);
};

vector <string> TextEditor::twoColumn(vector <string> text, int width) {
	int now = 0;
	vector<string> ans;
	string newL = "";
	for (int i = 0; i < text.size(); i ++) {
		stringstream sin(text[i]);
		string s;
		while (sin >> s) {
			if (newL != "") s = " " + s;
			if (now + s.length() <= width) {
				now += s.length();
				newL += s;
			} else {
				ans.push_back(newL);
				now = s.length() - 1;
				newL = s.substr(1);
			}
		}
	}
	if (newL != "") ans.push_back(newL);
	int sz = ans.size();
	vector<string> ret;
	for (int i = 0; i + i < sz; i ++) {
		ret.push_back(ans[i]);
		if (i + (sz + 1) / 2 < sz) ret.push_back(ans[i + (sz + 1) / 2]);
	}
	return ret;
}
//Powered by [KawigiEdit] 2.0!
