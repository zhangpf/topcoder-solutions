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

class CrossWord {
public:
	int countWords(vector <string>, int);
};

int CrossWord::countWords(vector <string> s, int size) {
	int ans = 0, n = s.size(), m = s[0].length();
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j + size <= m; j ++) {
			if (j && s[i][j - 1] == '.') continue;
			if (j + size < m && s[i][j + size] == '.') continue;
			int ok = 1;
			for (int k = 0; k < size && ok; k ++) if (s[i][j + k] == 'X') ok = 0;
			if (ok) ans ++;
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
