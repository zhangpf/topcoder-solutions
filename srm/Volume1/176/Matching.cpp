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

const string shape[3] = { "CIRCLE", "DIAMOND", "SQUIGGLE" };
const string color[3] = { "BLUE", "GREEN", "RED" };
const string shading[3] = { "EMPTY", "SOLID", "STRIPED" };
const string number[3] = { "ONE", "THREE", "TWO" };

class Matching {
	string otherShape(string x, string y) {
		if (x > y) swap(x, y);
		if (x != shape[0]) return shape[0];
		if (y != shape[1]) return shape[1];
		return shape[2];
	}
	string otherColor(string x, string y) {
		if (x > y) swap(x, y);
		if (x != color[0]) return color[0];
		if (y != color[1]) return color[1];
		return color[2];
	}
	string otherShading(string x, string y) {
		if (x > y) swap(x, y);
		if (x != shading[0]) return shading[0];
		if (y != shading[1]) return shading[1];
		return shading[2];
	}
	string otherNumber(string x, string y) {
		if (x > y) swap(x, y);
		if (x != number[0]) return number[0];
		if (y != number[1]) return number[1];
		return number[2];
	}
public:
	vector <string> findMatch(vector <string>, vector <string>);
};

vector <string> Matching::findMatch(vector <string> s0, vector <string> s1) {
	vector<string> ans;
	if (s0[0] == s1[0]) ans.push_back(s0[0]);
	else ans.push_back(otherShape(s0[0], s1[0]));
	if (s0[1] == s1[1]) ans.push_back(s0[1]);
	else ans.push_back(otherColor(s0[1], s1[1]));
	if (s0[2] == s1[2]) ans.push_back(s0[2]);
	else ans.push_back(otherShading(s0[2], s1[2]));
	if (s0[3] == s1[3]) ans.push_back(s0[3]);
	else ans.push_back(otherNumber(s0[3], s1[3]));
	return ans;
}

//Powered by [KawigiEdit] 2.0!
