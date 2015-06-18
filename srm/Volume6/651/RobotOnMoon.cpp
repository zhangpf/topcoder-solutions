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

class RobotOnMoon {
public:
	int longestSafeCommand(vector <string>);
};

int RobotOnMoon::longestSafeCommand(vector <string> board) {
	int sx = 0, sy = 0, n = board.size(), m = board[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (board[i][j] == 'S') {
				sx = i; sy = j;
			}
		}
	}
	int ok = 0;
	for (int i = 0; !ok && i < n; i ++) if (board[i][sy] == '#') ok = 1;
	for (int i = 0; !ok && i < m; i ++) if (board[sx][i] == '#') ok = 1;
	if (ok) return -1;
	return n + m - 2;
}

//Powered by [KawigiEdit] 2.0!
