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
const int maxn = 60;

class Gems {
	char c[maxn][maxn];
	char d[maxn][maxn];
	int n, m;
	int out(int x, int y) {
		return x < 0 || y < 0 || x >= n || y >= m;
	}
	int check(int x1, int y1, int x2, int y2) {
		if (out(x1, y1) || out(x2, y2)) return 0;
		for (int i = 0; i < n; i ++) for (int j = 0; j < m; j ++) {
			d[i][j] = c[i][j];
			if (x1 == i && y1 == j) d[i][j] = c[x2][y2];
			if (x2 == i && y2 == j) d[i][j] = c[x1][y1];
		}
		for (int i = 0; i < n - 2; i ++) for (int j = 0; j < m; j ++) {
			if (d[i][j] == d[i + 1][j] && d[i][j] == d[i + 2][j]) return 1;
		}
		for (int i = 0; i < n; i ++) for (int j = 0; j < m - 2; j ++) {
			if (d[i][j] == d[i][j + 1] && d[i][j] == d[i][j + 2]) return 1;
		}
		return 0;
	}
public:
	int numMoves(vector <string>);
};

int Gems::numMoves(vector <string> board) {
	n = board.size();
	m = board[0].length();
	int ans = 0;
	for (int i = 0; i < n; i ++) 
		for (int j = 0; j < m; j ++) 
			c[i][j] = board[i][j];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			ans += check(i, j, i - 1, j);
			ans += check(i, j, i, j - 1);
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
