#line 5 "ApplesAndOrangesEasy.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class ApplesAndOrangesEasy {
	int mk[2010] = {0};
	public:
	int maximumApples(int N, int K, vector <int> info) {
		for (int i = 0; i < info.size(); i++) {
			mk[info[i]-1] = 1;
		}
		int cnt = 0, now = 0;
		for (int i = 0; i < N; i++) {
			if (i-K >= 0 && mk[i-K]) now --;
			if (mk[i]) cnt ++, now ++;
			else {
				int cur = now + 1, ok = 1;
				if (cur > K/2) continue;
				for (int j = 1; ok && j < K && j + i < N; j++) {
					if (mk[j+i]) cur ++; 
					if (i+j-K >= 0 && mk[i+j-K]) cur --;
					if (cur > K/2) ok = 0;
				}
				if (ok) {
					cnt ++;
					mk[i] = 1;
					now ++;
				}
			}
		}
		return cnt;
	}
};

// Powered by FileEdit
