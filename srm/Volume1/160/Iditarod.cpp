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

class Iditarod {
public:
	int avgMinutes(vector <string>);
};

int Iditarod::avgMinutes(vector <string> times) {
	double sum = 0;
	for (int i = 0; i < times.size(); i ++) {
		stringstream sin(times[i]);
		int h, m, d, mm;
		char c;
		string s1, s2;
		sin >> h >> c >> m >> s1 >> s2 >> d;
		mm = (d - 1) * 1440;
		if (h == 12) h = 0;
		if (s1[0]== 'A') {
			mm += (h * 60) + m;
		} else {
			mm += (h * 60) + m + 720;
		}
		printf("%d\n", mm);
		sum += (mm - 480);
	}
	return (int)(sum / times.size() + 0.5);
}

//Powered by [KawigiEdit] 2.0!
