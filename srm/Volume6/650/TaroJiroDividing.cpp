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

class TaroJiroDividing {
public:
	int getNumber(int, int);
};

int TaroJiroDividing::getNumber(int A, int B) {
	while (A > B && A % 2 == 0) A >>= 1;
	while (B > A && B % 2 == 0) B >>= 1;
	if (B != A) return 0;
	int ans = 1;
	while (B % 2 == 0) B >>= 1, ans ++;
	return ans;
}
//Powered by [KawigiEdit] 2.0!
