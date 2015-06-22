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

class PartySeats {
	vector<string> b, g;
public:
	vector <string> seating(vector <string>);
};

vector <string> PartySeats::seating(vector <string> s) {
	vector<string> ans;
	for (int i = 0; i < s.size(); i ++) {
		stringstream sin(s[i]);
		string name, gender;
		sin >> name >> gender;
		if (gender == "boy") b.push_back(name);
		else g.push_back(name);
	}
	if (g.size() != b.size() || b.size() % 2) return ans;
	sort(b.begin(), b.end());
	sort(g.begin(), g.end());
	int now = 0, bit = 0, git = 0, sz = b.size();
	while (bit < sz || git < sz) {
		if (now == 0) ans.push_back("HOST");
		else if (now == sz + 1) ans.push_back("HOSTESS");
		else if (now % 2) ans.push_back(g[git ++]);
		else ans.push_back(b[bit ++]);
		now ++;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
