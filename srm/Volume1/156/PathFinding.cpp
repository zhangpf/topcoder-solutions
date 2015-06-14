#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <memory>
#include <cstring>
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
const int MAXN = 30;
const int QLEN = 160010;

class PathFinding {
	int c[MAXN][MAXN][MAXN][MAXN];
	int qxa[QLEN], qxb[QLEN], qya[QLEN], qyb[QLEN], cur, tail;
public:
	int minTurns(vector <string>);
};

const int ox[9] = {0, 0, 0, 1, 1, 1, -1, -1, -1};
const int oy[9] = {1, 0, -1, 1, 0, -1, 1, 0, -1};

int PathFinding::minTurns(vector <string> board) {
	memset(c, 0xff, sizeof(c));
	int sxa, sxb, sya, syb;
	int n = board.size(), m = board[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (board[i][j] == 'A') {
				sxa = i; sya = j;
				board[i][j] = '.';
			} else if (board[i][j] == 'B') {
				sxb = i; syb = j;
				board[i][j] = '.';
			}
		}
	}
	qxa[0] = sxa, qxb[0] = sxb, qya[0] = sya, qyb[0] = syb;
	cur =0, tail = 1;
	c[sxa][sya][sxb][syb] = 0;
	while (cur < tail) {
		int xa = qxa[cur], xb = qxb[cur], ya = qya[cur], yb = qyb[cur];
		if (sxa == xb && sya == yb && sxb == xa && syb == ya) {
			return c[xa][ya][xb][yb];
		}
		cur ++;
		for (int i = 0; i < 9; i ++) {
			int txa = xa + ox[i];
			int tya = ya + oy[i];
			if (txa < 0 || txa >= n || tya < 0 || tya >= m || board[txa][tya] == 'X') continue;
			for (int j = 0; j < 9; j ++) {
				int txb = xb + ox[j];
				int tyb = yb + oy[j];
				if (txb < 0 || txb >= n || tyb < 0 || tyb >= m || board[txb][tyb] == 'X') continue;
				if (txa == xb && tya == yb && txb == xa && tyb == ya) continue;
				if (txa == txb && tya == tyb) continue;
				if (c[txa][tya][txb][tyb] != -1) continue;
				c[txa][tya][txb][tyb] = c[xa][ya][xb][yb] + 1;
				qxa[tail] = txa;
				qxb[tail] = txb;
				qya[tail] = tya;
				qyb[tail] = tyb;
				tail ++;
			}
		}
	}
	return -1;
}

//Powered by [KawigiEdit] 2.0!
