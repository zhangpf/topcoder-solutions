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

class EightRooks {
public:
	string isCorrect(vector <string>);
};

string EightRooks::isCorrect(vector <string> board) {
	int ok = 1, s = 0;
	for (int i = 0; ok && i < 8; i ++) {
		int t = 0, cnt = 0; 
		for (int j = 0; ok && j < 8; j ++) {
			if (board[i][j] == 'R') {
				cnt ++;
				t |= (1 << j);
				if (cnt >= 2) ok = 0;
			}
		}
		s |= t;
	}
	if (ok && s == 255) return "Correct";
	else return "Incorrect";
	
}

//Powered by [KawigiEdit] 2.0!
