#line 5 "AB.cpp"
#include <string>
#include <list>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
const int maxn = 51;
const int maxp = 2501;
class AB {
	string s[maxn][maxn][maxp];
	int mk[maxn][maxn][maxp];
	public:
	string createString(int N, int K) {
		memset(mk, 0, sizeof(mk));
		mk[0][0][0] = 1;
		s[0][0][0] = "";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				for (int k = 0; k <= K; k++) if(mk[i][j][k]) {
					if (k+j <= K && !mk[i+1][j][k+j]) {
						mk[i+1][j][k+j] = 1;
						s[i+1][j][k+j] = s[i][j][k] + 'B';
					}
					if (!mk[i+1][j+1][k]) {
						mk[i+1][j+1][k] = 1;
						s[i+1][j+1][k] = s[i][j][k] + 'A';
					}
				}
			}
		}
		int found = -1;
		for (int i = 0; found == -1 && i <= N; i++) {
			if(mk[N][i][K]) found = i;
		}
		if (-1 == found) return "";
		else return s[N][found][K];
 	}
};


// Powered by FileEdit
