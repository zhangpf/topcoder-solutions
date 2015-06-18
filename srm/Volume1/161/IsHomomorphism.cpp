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

class IsHomomorphism {
public:
	vector <string> numBad(vector <string>, vector <string>, vector <int>);
};

vector <string> IsHomomorphism::numBad(vector <string> source, vector <string> target, vector <int> mapping) {
	int n = source.size();
	vector<string> ans;
	for (int i = 0; i < n; i ++) for (int j = 0; j < n; j ++) {
		int s = source[i][j] - '0';
		if (mapping[s] + '0' != target[mapping[i]][mapping[j]]) {
			ans.push_back("(" + to_string(i) + "," + to_string(j) + ")");
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
