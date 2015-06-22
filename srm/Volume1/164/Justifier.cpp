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

class Justifier {
public:
	vector <string> justify(vector <string>);
};

vector <string> Justifier::justify(vector <string> textIn) {
	int len = 0;
	vector<string> ans;
	for (int i = 0; i < textIn.size(); i ++) {
		len = max(len, (int)textIn[i].length());
	}
	for (int i = 0; i < textIn.size(); i ++) {
		string now = textIn[i];
		while (now.length() < len) {
			now = " " + now;
		}
		ans.push_back(now);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
