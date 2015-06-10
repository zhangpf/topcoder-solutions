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

class PrefixCode {
public:
	string isOne(vector <string>);
};

string PrefixCode::isOne(vector <string> words) {
	for (int i = 0; i < words.size(); i ++) {
		for (int j = 0; j < words.size(); j ++) if (i != j) {
			if (words[j].substr(0, words[i].length()) == words[i]) return "No, " + to_string(i);
		}
	}
	return "Yes";
}

//Powered by [KawigiEdit] 2.0!
