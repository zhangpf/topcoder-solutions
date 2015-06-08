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

class BichromeBoard {
	int paint(char c, vector <string> b) {
		for (int i = 0; i < b.size(); i ++) {
			for (int j = 0; j < b[0].length(); j ++) {
				if (b[i][j] == '?') continue;
				if (b[i][j] == c && (i + j) % 2) return 0;
				if (b[i][j] != c && (i + j) % 2 == 0) return 0;
			}
		}
		return 1;
	}
public:
	string ableToDraw(vector <string>);
};

string BichromeBoard::ableToDraw(vector <string> board) {
	if (paint('B', board) || paint('W', board))
		return "Possible";
	return "Impossible";
}

//Powered by [KawigiEdit] 2.0!
