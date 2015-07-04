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

class WordForm {
	void update(string &x, char c) {
		if (x.length() == 0) x += c;
		else if (x[x.length() - 1] == c) return;
		else x += c;
	}
public:
	string getSequence(string);
};

string WordForm::getSequence(string word) {
	string ans = "";
	int now = 0;
	for (char c: word) {
		c = tolower(c);
		if (c == 'y' && now) update(ans, 'V'), now = 0;
		else if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') update(ans, 'V'), now = 0;
		else update(ans, 'C'), now = 1;  
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
