#line 5 "Masterbrain.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Masterbrain {
	int g[10][10];
	int rb[10], rw[10];
	int n;
	int check(int s[], int t) {
		int b = 0, w = 0;
		int mk1[4] = {0}, mk[4] = {0};
		for (int i = 0; i < 4; i++ ) {
			if (s[i] == g[t][i]) {
				mk[i] = 1;
				mk1[i] = 1;
				b ++;
			}
		}
		for (int i = 0; i < 4; i++ ) if (!mk1[i]) {
			for (int j = 0; j < 4; j++) {
				if (mk[j] == 0 && s[j] == g[t][i]) {
					mk[j] = 1;
					w ++; break;
				}
			}
		}
		return !(rb[t] == b && rw[t] == w);
	}
	public:
	int possibleSecrets(vector <string> guesses, vector <string> results) {
		n = guesses.size();
		for (int i = 0; i < n; i ++) {
			for (int k = 0; k < 4; k ++) {
				g[i][k] = guesses[i][k] - '0';
				cout << g[i][k] << " ";
			}
			rb[i] = results[i][0] - '0';
			rw[i] = results[i][3] - '0';
			//cout << " " << rb[i] << " " << rw[i] << endl; 
		}
		int ans = 0;
		int s[4];
		for (int i = 1; i <= 7; i ++) { s[0] = i;
			for (int j = 1; j <= 7; j ++) { s[1] = j;
				for (int k = 1; k <= 7; k ++) { s[2] = k;
					for (int t = 1; t <= 7; t ++) { s[3] = t;
						int tmp = 0;
						for (int f = 0; tmp <= 1 && f < n; f ++) tmp += check(s, f);
						if (tmp == 1) ans ++;
						//else cout << i << " " << j << " " << k << " " << t << endl;
					}
				}
			}
		}
		return ans;
	}
};


// Powered by FileEdit
