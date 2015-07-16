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

class Removal {
public:
	int finalPos(int, int, vector <string>);
};

int Removal::finalPos(int n, int K, vector <string> remove) {
	long long k = K;
	for (int i = remove.size() - 1; i >= 0; i --) {
		stringstream sin(remove[i]);
		int b, e; char c;
		sin >> b >> c >> e;
		if (b <= k) k += (e - b + 1);
	}
	return (k > n) ? -1 : k;
}

//Powered by [KawigiEdit] 2.0!
