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

class CheatCode {
public:
	vector <int> matches(string, vector <string>);
};

vector <int> CheatCode::matches(string k, vector <string> c) {
	vector<int> ans;
	for (int i = 0; i < c.size(); i ++) {
		int cur = 0, done = 0;
		while (!done  && cur < k.size()) {
			int ok = 1, now = cur;
			for (int j = 0; ok && j < c[i].length(); j ++) {
				if (now >= k.size()) {
					ok = 0;
					continue;
				}
				if (c[i][j] == k[now]) {
					now ++;
					continue;
				}
				while (now < k.size() && k[now] == c[i][j - 1]) now ++;
				if (now == k.size()) {
					ok = 0;
				} else {
					if (k[now] != c[i][j]) ok = 0;
					else now ++;
				}
			}
			if (ok) done = 1;
			cur ++;
		}
		if (done) ans.push_back(i);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
