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
const int maxn = 110;

class ContestScore {
	int n, m;
	int id[maxn];
	class p {
	public:
		string name;
		int sum1;
		int sum2;
		friend int operator < (const p & p1, const p &p2) {
			if (p1.sum1 != p2.sum1) return p1.sum1 < p2.sum1;
			if (p1.sum2 != p2.sum2) return p1.sum2 > p2.sum2;
			return p1.name < p2.name;
		}
	} t[110];
	
public:
	vector <string> sortResults(vector <string>);
};

int s[110][110];
int cur;
static int cmp(const int &i, const int &j) {
	return s[i][cur] > s[j][cur];
}

vector <string> ContestScore::sortResults(vector <string> data) {
	n = data.size();
	int cnt = 0; 
	for (int i = 0; i < n; i ++) {
		stringstream sin(data[i]);
		double x;
		sin >> t[i].name;
		cnt = 0;
		while (sin >> x) {
			s[i][cnt] = (int)(x * 10 + 1e-8);
			cnt ++;
		}
	}
	m = cnt;
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) id[j] = j;
		cur = i;
		sort(id, id + n, cmp);
		int now  = 1;
		for (int j = 0; j < n; j ++) {
			if (j && s[id[j]][cur] == s[id[j - 1]][cur]) {
				t[id[j]].sum1 += now;
			} else {
				now = j + 1;
				t[id[j]].sum1 += now;
			}
			t[id[j]].sum2 += s[id[j]][i];
		}
	}
	sort(t, t + n);
	vector<string> ans;
	for (int i = 0; i < n; i ++) {
		string st = t[i].name + " " + to_string(t[i].sum1) + " ";
		int k1 = t[i].sum2 / 10;
		int k2 = t[i].sum2 % 10;
		st += to_string(k1) + "." + to_string(k2);
		ans.push_back(st);
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
