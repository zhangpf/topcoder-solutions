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

class Archimedes {
public:
	double approximatePi(int);
};

double Archimedes::approximatePi(int n) {
	return sin(acos(-1.0) / n) * n;
}

//Powered by [KawigiEdit] 2.0!
