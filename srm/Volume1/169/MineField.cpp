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

class MineField {
public:
	vector <string> getMineField(string);
};

const int ox[8] = {0, 0, -1, 1, 1, 1, -1, -1};
const int oy[8] = {1, -1, 0, 0, -1, 1, -1, 1};

vector <string> MineField::getMineField(string s) {
	stringstream sin(s);
	char c;
	int x, y;
	vector<string> b(9, "000000000");
	while (sin >> c >> x >> c >> y >> c) {
		b[x][y] = 'M';
	}
	for (int i = 0; i < 9; i ++) for (int j = 0; j < 9; j ++) {
		if (b[i][j] == 'M') continue;
		int cnt = 0;
		for (int k = 0; k < 8; k ++) {
			int tx = i + ox[k];
			int ty = j + oy[k]; 
			if (tx < 0 || ty < 0 || tx >= 9 || ty >= 9) continue;
			if (b[tx][ty] == 'M') cnt ++;
		}
		b[i][j] = '0' + cnt;
	}
	return b;
}


//Powered by [KawigiEdit] 2.0!
