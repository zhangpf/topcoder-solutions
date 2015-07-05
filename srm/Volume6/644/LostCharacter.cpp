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

class LostCharacter {
	vector<string> calcB(vector<string> s) {
		for (int i = 0; i < s.size(); i ++) {
			for (int j = 0; j < s[i].length(); j ++) if (s[i][j] == '?') s[i][j] = 'z';
		}
		return s;
	}
public:
	vector <int> getmins(vector <string>);
};

vector <int> LostCharacter::getmins(vector <string> str) {
	vector <string> b = calcB(str);
	vector<int> ans;
	for (int i = 0; i < str.size(); i ++) {
		string now = str[i];
		for (int j = 0; j < now.length(); j ++) {
			if (now[j] == '?') now[j] = 'a';
		}
		int k = 0;
		for (int j = 0; j < str.size(); j ++) if (j != i && b[j] < now) k ++;
		ans.push_back(k);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
