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
const int maxn = 2500;
const int maxm = 51;

class DirectoryTree {
	string name[maxn];
	int num;
	vector<int> nxt[maxn];
	void add(vector<string> p) {
		int now = 1, cur = 0;
		while (cur < p.size()) {
			int found = 0;
			for (int i = 0; !found && i < nxt[now].size(); i ++) {
				int idx = nxt[now][i];
				if (name[idx] == p[cur]) {
					now = idx;
					found = 1;
				}
			}
			if (!found) {
				nxt[now].push_back(++ num);
				name[num] = p[cur];
				now = num;
			}
			cur ++;
		}
	}
	vector<string> dfs(int x, int h, int &sum, int f) {
		vector<string> ans;
		if (h == 0) ans.push_back("ROOT");
		else {
			ans.push_back("+-" + name[x]);
		}
		vector<int> mk(nxt[x].size());
		sum = 1; 
		int sz;
		for (int i = 0; i < nxt[x].size(); i ++) {
			int ch = -1;
			for (int j = 0; j < nxt[x].size(); j ++) if(!mk[j]) {
				if (ch == -1 || name[nxt[x][ch]] > name[nxt[x][j]]) ch = j;
			}
			mk[ch] = 1;
			vector<string> tmp = dfs(nxt[x][ch], h + 1, sz, (i + 1 != nxt[x].size()));
			for (string it: tmp) { ans.push_back(it); }
			sum += sz;
		}
		string pre = "";
		if (f && ans.size() >= 2) pre = "| ";
		else if (h) pre = "  ";
		for (int i = 1; i < ans.size(); i ++) ans[i] = pre + ans[i];
		return ans;
	}
public:
	vector <string> display(vector <string>);
};

vector <string> DirectoryTree::display(vector <string> files) {
	num = 1;
	for (int i = 0; i < files.size(); i ++) {
		vector<string> s;
		int now = 1, h;
		while ((h = files[i].find('/', now)) != std::string::npos) {
			s.push_back(files[i].substr(now, h - now));
			now = h + 1;
		}
		s.push_back(files[i].substr(now));
		add(s);
	}
	for (int i = 0; i < nxt[1].size(); i ++) cout << nxt[1][i] << endl;
	int sz;
	return dfs(1, 0, sz, 0);
}

//Powered by [KawigiEdit] 2.0!
