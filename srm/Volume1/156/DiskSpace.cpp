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

class DiskSpace {
public:
	int minDrives(vector <int>, vector <int>);
};

int DiskSpace::minDrives(vector <int> used, vector <int> total) {
	int sum = 0;
	for (int i = 0; i < used.size(); i ++) sum += used[i];
	sort(total.begin(), total.end());
	int sum2 = 0;
	for (int i = total.size() - 1; i >= 0; i --) {
		sum2 += total[i];
		if (sum2 >= sum) return total.size() - i;
	}
	return -1;
}

//Powered by [KawigiEdit] 2.0!
