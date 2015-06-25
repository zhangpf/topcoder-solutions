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

class Workshop {
public:
	int pictureFrames(vector <int>);
};

int Workshop::pictureFrames(vector <int> p) {
	sort(p.begin(), p.end());
	int ans = 0, n = p.size();
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			for (int k = j + 1; k < n; k ++) {
				if (p[i] + p[j] > p[k]) ans ++;
			}
		}
	}
	return ans;
}

//Powered by [KawigiEdit] 2.0!
