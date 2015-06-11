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
const int INF = 1000000000;

class QuiningTopCoder {
	int stack[80010];
	int sp;
	int pop() {
		if (sp == 0) return 0;
		int res = stack[sp - 1];
		sp --;
		return res;
	}
	int push(int x) {
		if (x < - INF || x > INF) return 0;
		stack[sp ++] = x;
		return 1;
	}
public:
	string testCode(string);
};

string QuiningTopCoder::testCode(string source) {
	int ip = 0, d = 1, recover = 0;
	sp = 0;
	int ok = 0, times = 0, n = source.length();
	string ans = "";
	while (!ok && times < 80000) {
		times ++;
		//printf("ip = %d\n", ip);
		char c = source[ip];
		if (c >= '0' && c <= '9') push(c - '0');
		else if (c == '$') pop();
		else if (c == ':') {
			int x = pop();
			if (!push(x) || !push(x)) {
				ok = -1;
			}
		} else if (c == 'W') {
			int x = pop(), y = pop();
			if (!push(x) || !push(y)) {
				ok = -1;
			}
		} else if (c == ',') {
			int x = pop();
			ans += source[abs(x) % n];
			int len = ans.length();
			if (len <= n && ans[len - 1] != source[len - 1]) {
				ok = -2;
			} else if (len == n) {
				ok = 1;
			}
		} else if (c == '+') {
			int x = pop(), y = pop();
			if (!push(x + y)) ok = -1;
		} else if (c == '-') {
			int x = pop(), y = pop();
			if (!push(x - y)) ok = -1;
		} else if (c == '#') {
			d *= 2; recover = 1;
		} else if (c == 'R') {
			d = -d;
		} else if (c == 'S') {
			int x = pop();
			push(x > 0 ? 1 : -1);
		} else if (c == '_') {
			d = pop() % n;
		} else if (c == 'J') {
			ip = abs(pop()) % n; 
		} else if (c == '@') {
			ok = -3;
		}
		if (c != 'J') ip = (ip + d + 3 * n) % n;
		if (recover) {
			recover = 0; d /= 2;
		}
	}
	if (ok == 0) return "TIMEOUT";
	times --;
	if (ok == -3) return "BADEND " + to_string(times);
	else if (ok == -1) return "OVERFLOW " + to_string(times);  
	else if (ok == -2) return "MISMATCH " + to_string(times);
	else return "QUINES " + to_string(times);
}

//Powered by [KawigiEdit] 2.0!
