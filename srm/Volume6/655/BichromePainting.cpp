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

class BichromePainting {
public:
	string isThatPossible(vector <string>, int);
};

string BichromePainting::isThatPossible(vector <string> board, int k) {
	int n = board.size();
	int ok = 1;
	while (ok) {
		int done = 1;
		for (int i = 0; done && i < n; i ++) {
			for (int j = 0; done && j < n; j ++) {
				if (board[i][j] == 'B') done = 0;
			} 
		}
		if (done) break;
		ok = 0;
		for (int i = 0; !ok && i + k <= n; i ++) {
			for (int j = 0; !ok && j + k <= n; j ++) {
				char c = '?';
				int found = 1;
				for (int t = 0; found && t < k; t ++) for (int s = 0; found && s < k; s ++) {
					if (board[i + t][j + s] == 'B' && c != 'B') {
						if (c == '?') c = 'B';
						else found = 0;
					} else if (board[i + t][j + s] == 'W' && c != 'W') {
						if (c == '?') c = 'W';
						else found = 0;
					}
				}
				if (found && c != '?') {
					//printf ("%d %d %c\n", i, j, c);
					ok = 1;
					for (int t = 0; t < k; t ++) for (int s = 0; s < k; s ++) {
						board[i + t][j + s] = '?';
					}
				}
			}
		}
	}
	if (ok) return "Possible";
	else return "Impossible";
}

//Powered by [KawigiEdit] 2.0!
