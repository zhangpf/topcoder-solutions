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

class SMBus {
public:
	int transmitTime(vector <string>, vector <int>);
};

int SMBus::transmitTime(vector <string> messages, vector <int> times) {
	int ans = 0;
	int n = messages.size();
	vector<int> ch(n);
	for (int i = 0; i < n; i ++) {
		int done = 0, len = 0;
		vector<int> mk(n);
		while (!done) {
			done = 1;
			char c = '9';
			for (int j = 0; j < n; j ++) if (len < messages[j].length() && !mk[j] && !ch[j]) {
				c = min(c, messages[j][len]);
				done = 0;
			}
			if (done) break;
			int nowT = 0;
			for (int j = 0; j < n; j ++) if (!mk[j] && !ch[j]) {
				if (c != messages[j][len]) mk[j] = 1;
				nowT = max(nowT, times[j]);
			}
			ans += nowT;
			len ++;
		}
		for (int j = 0; j < n; j ++) if (!mk[j] && !ch[j]) ch[j] = 1;
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
