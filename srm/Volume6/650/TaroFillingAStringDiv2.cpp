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

class TaroFillingAStringDiv2 {
public:
	int getNumber(string);
};

int TaroFillingAStringDiv2::getNumber(string S) {
	int b = -1;
	int ans = 0, now = 0;
	while (now < S.length()) {
		if (S[now] != '?') {
			if (b != -1) {
				if (S[b] == S[now] && (now - b) % 2) ans ++;
				if (S[b] != S[now] && (now - b) % 2 == 0) ans ++;
			}
			b = now;
		} 
		now ++;
	}
	return ans;
}
//Powered by [KawigiEdit] 2.0!
