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
#include <cstring>
#include <memory>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
const int maxn = 51;

class AB {
	int mk[maxn][maxn][maxn * maxn];
	string ans[maxn][maxn][maxn * maxn];
public:
	string createString(int, int);
};

string AB::createString(int N, int K) {
	memset(mk, 0, sizeof(mk));
	ans[0][0][0] = "";
	mk[0][0][0] = 1;
	for (int i = 0; i < N; i ++) for (int k = 0; k <= i; k ++){
		for (int j = 0; j <= K; j ++) if (mk[i][k][j]) {
			if (!mk[i + 1][k + 1][j]) {
				mk[i + 1][k + 1][j] = 1;
				ans[i + 1][k + 1][j] = ans[i][k][j] + 'A';
			} 
			if (!mk[i + 1][k][j + k]) {
				mk[i + 1][k][j + k] = 1;
				ans[i + 1][k][j + k] = ans[i][k][j] + 'B';
			}
		}
	}
	for (int i = 0; i <= N; i ++) if (mk[N][i][K]) return ans[N][i][K];
	return "";
}	
//Powered by [KawigiEdit] 2.0!
