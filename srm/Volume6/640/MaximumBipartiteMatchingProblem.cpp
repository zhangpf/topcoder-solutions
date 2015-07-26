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

class MaximumBipartiteMatchingProblem {
public:
	long long solve(int, int, int, int);
};

long long MaximumBipartiteMatchingProblem::solve(int n1, int n2, int ans, int d) {
	long res = -1;
     
	    // the four values of x:
	    // n1      : fill the left side with vertices to cut. 
	    // n2 - ans: fill the right side with vertices to cut
	    // d       : The case in which the left side has as little as posive
	    // ans - d : The case in which the right side has as little as posive
	    //
	    for (int x: {n1, ans - d, n2 - ans, d} ) {
	        long y = ans - x;
	        if ( (0 <= x && x <= ans) 
	             && (x == n1 || y >= d) && (y == n2 || x >= d) ) {
	            res = max(res, (long)n1*n2 - (n1-x)*(n2-y));
	        }
	    }        
	    return res;
}
//Powered by [KawigiEdit] 2.0!
