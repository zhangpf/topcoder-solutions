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

class BombSweeper {
public:
	double winPercentage(vector <string>);
};
const int tx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
const int ty[8] = {1, -1, 0, 0, -1, 1, 1, -1};

double BombSweeper::winPercentage(vector <string> board) {
	int n = board.size();
	int win = 0, lose = 0;
	int m = board[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (board[i][j] == 'B') lose ++;
			else {
				int ok = 1;
				for (int k = 0; ok && k < 8; k ++) {
					int ox = tx[k] + i;
					int oy = ty[k] + j;
					if (ox >= 0 && ox < n && oy >=0 && oy < m && board[ox][oy] == 'B') ok = 0;
				}
				if (ok) win ++;
			}
		}
	}
	return (win * 100.0 / (win + lose));
}	

//Powered by [KawigiEdit] 2.0!
