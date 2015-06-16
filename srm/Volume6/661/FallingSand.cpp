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

class FallingSand {
public:
	vector <string> simulate(vector <string>);
};

vector <string> FallingSand::simulate(vector <string> board) {
	int done = 0;
	while (!done) {
		done = 1;
		for (int i = 0; done && i < board.size(); i ++) {
			for (int j = 0; done && j < board[0].length(); j ++) {
				if (i < board.size() - 1 && board[i][j] == 'o' && board[i + 1][j] == '.') {
					board[i + 1][j] = 'o';
					board[i][j] = '.';
					done = 0;
				}
			}
		}
	}
	return board;
}

//Powered by [KawigiEdit] 2.0!
