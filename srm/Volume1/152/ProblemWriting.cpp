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

class ProblemWriting {
	int check(string x) {
		if (x.length() == 1) {
			if (x[0] >= '0' && x[0] <= '9') return -1;
			return 0;
		} 
		int s = 0;
		for (int i = 0; i < x.length(); i ++) {
			if (s == 0) {
				if (x[i] >= '0' && x[i] <= '9') s = 1;
				else return i;
			} else if (s == 1) {
				if (x[i] == '.') s = 3;
				else if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') s = 2;
				else return i;
			} else if (s == 2) {
				if (x[i] == '.') s = 4;
				else if (x[i] >= '0' && x[i] <= '9') s = 1;
				else return i;
			} else if (s == 3) {
				if (x[i] == '.') continue;
				else if (x[i] == '+' || x[i] == '-' || x[i] == '*' || x[i] == '/') s = 2;
				else return i;
			} else if (s == 4) {
				if (x[i] >= '0' && x[i] <= '9') s = 1;
				else if (x[i] != '.') return i;
			}
		}
		if (s == 1) return -1;
		else return x.length();
	}
public:
	string myCheckData(string);
};

string ProblemWriting::myCheckData(string d) {
	if (d.length() == 0 || d.length() > 25) {
		return "dotForm must contain between 1 and 25 characters, inclusive.";
	}
	int res = check(d);
	if (res == -1) return "";
	return "dotForm is not in dot notation, check character " + to_string(res) + ".";
}

//Powered by [KawigiEdit] 2.0!
