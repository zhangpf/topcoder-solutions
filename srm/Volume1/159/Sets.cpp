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

class Sets {
	vector<int> unions(vector<int> a, vector<int> b) {
		vector<int> ans;
		for (int i = 0; i < a.size(); i ++) {
			int found = 0;
			for (int j = 0; !found && j < b.size(); j ++) {
				if (b[j] == a[i]) found = 1;
			}
			if (!found) ans.push_back(a[i]);
		}
		for (int i = 0; i < b.size(); i ++) ans.push_back(b[i]);
		sort(ans.begin(), ans.end());
		return ans;
	}
	vector<int> intersection(vector<int> a, vector<int> b) {
		vector<int> ans;
		for (int i = 0; i < a.size(); i ++) {
			int found = 0;
			for (int j = 0; !found && j < b.size(); j ++) {
				if (b[j] == a[i]) found = 1;
			}
			if (found) ans.push_back(a[i]);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
	vector<int> diff(vector<int> a, vector<int> b) {
		vector<int> ans;
		for (int i = 0; i < a.size(); i ++) {
			int found = 0;
			for (int j = 0; !found && j < b.size(); j ++) {
				if (b[j] == a[i]) found = 1;
			}
			if (!found) ans.push_back(a[i]);
		}
		for (int i = 0; i < b.size(); i ++) {
			int found = 0;
			for (int j = 0; !found && j < a.size(); j ++) {
				if (a[j] == b[i]) found = 1;
			}
			if (!found) ans.push_back(b[i]);
		}
		sort(ans.begin(), ans.end());
		return ans;
	}
public:
	vector <int> operate(vector <int>, vector <int>, string);
};

vector <int> Sets::operate(vector <int> A, vector <int> B, string operation) {
	if (operation == "UNION") return unions(A, B);
	else if (operation == "INTERSECTION") return intersection(A, B);
	else return diff(A, B);
}

//Powered by [KawigiEdit] 2.0!
