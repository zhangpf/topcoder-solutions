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

class Birthday {
	int calc(string date) {
		int mm = (date[0] - '0') * 10 + (date[1] - '0');
		int dd = (date[3] - '0') * 10 + (date[4] - '0');
		return mm * 31 + dd;
	}
public:
	string getNext(string, vector <string>);
};

string Birthday::getNext(string date, vector <string> birthdays) {
	int cur = calc(date);
	int least = cur - 1;
	string ans = "";
	for (int i = 0; i < birthdays.size(); i ++) {
		stringstream sin(birthdays[i]);
		string date;
		sin >> date;
		int d = calc(date);
		if (d >= cur && d < least) {
			least = d;
			ans = date;
		} else if (least < cur && (d >= cur || least > d)) {
			least = d;
			ans = date;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
