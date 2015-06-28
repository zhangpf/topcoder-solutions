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
#include <cstring>
#include <memory>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 31;
const int maxm = 450;

class ABC {
	int mk[maxn][maxn][maxn][maxm];
	string ans[maxn][maxn][maxn][maxm];
public:
	string createString(int, int);
};

string ABC::createString(int N, int K) {
	memset(mk, 0, sizeof(mk));
	mk[0][0][0][0] = 1;
	ans[0][0][0][0] = "";
	for (int i = 0; i < N; i ++) for (int j = 0; j <= i; j ++) {
		for (int k = 0; k <= i - j; k ++) for (int v = 0; v <= K; v ++) if(mk[i][j][k][v]) {
			if (!mk[i + 1][j + 1][k][v]) {
				mk[i + 1][j + 1][k][v] = 1;
				ans[i + 1][j + 1][k][v] = ans[i][j][k][v] + 'A';
			} 
			if (!mk[i + 1][j][k + 1][v + j]) {
				mk[i + 1][j][k + 1][v + j] = 1;
				ans[i + 1][j][k + 1][v + j] = ans[i][j][k][v] + 'B';
			}
			if (!mk[i + 1][j][k][v + j + k]) {
				mk[i + 1][j][k][v + j + k] = 1;
				ans[i + 1][j][k][v + j + k] = ans[i][j][k][v] + 'C';
			}
		}
	}
	for (int i = 0; i <= N; i ++) for (int j = 0; j + i <= N; j ++) {
		if (mk[N][i][j][K]) return ans[N][i][j][K];
	}
	return "";
}

//Powered by [KawigiEdit] 2.0!
