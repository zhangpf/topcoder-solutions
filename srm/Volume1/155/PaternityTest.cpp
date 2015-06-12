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

class PaternityTest {
public:
	vector <int> possibleFathers(string, string, vector <string>);
};

vector <int> PaternityTest::possibleFathers(string child, string mother, vector <string> men) {
	vector<int> ans;
	for (int i = 0; i < men.size(); i ++) {
		int cnt = 0, ok = 1;
		for (int j = 0; ok && j < child.length(); j ++) {
			int mk = 0;
			if (child[j] == mother[j]) mk += 1;
			if (child[j] == men[i][j]) mk += 2;
			if (mk == 0) ok = 0;
			else if (mk >= 2) cnt ++;
		}
		if (ok && cnt + cnt < child.length()) ok = 0;
		if (ok) ans.push_back(i);
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
