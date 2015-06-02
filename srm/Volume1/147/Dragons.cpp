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
typedef long long ll;
const int f[6][4] = {
	{2, 3, 4, 5},
	{2, 3, 4, 5},
	{0, 1, 4, 5},
	{0, 1, 4, 5},
	{0, 1, 2, 3},
	{0, 1, 2, 3}
};

class Dragons {
	static ll gcd(ll x, ll y) {
		if (x == 0) return y;
		return gcd(y % x, x);
	}
	class Fraction {
		ll x, y;
	public:
		Fraction() {
			x = 0; y = 1;
		}
		Fraction(ll _x, ll _y) {
			x = _x; y = _y;
		}
		Fraction operator + (const Fraction &other) {
			ll g = gcd(y, other.y);
			ll newY = y * (other.y / g);
			ll newX = x * (newY / y) + other.x * (newY / other.y);
			//printf("%lld %lld\n", newX, newY);
			ll newG = gcd(newX, newY);
			return Fraction(newX / newG, newY / newG);
		}
		Fraction operator / (const int d) {
			ll newY = y * d;
			ll g = gcd(newY, x);
			return Fraction(x / g, newY / g);
		}
		string format() {
			ll g = gcd(x, y);
			x /= g;
			y /= g;
			string ans = to_string(x);
			if (y != 1) ans += "/" + to_string(y);
			return ans;
		}
	};
	Fraction v[6];
	
public:
	string snaug(vector <int>, int);
};

string Dragons::snaug(vector <int> F, int r) {
	for (int i = 0; i < 6; i++) v[i] = Fraction(F[i], 1);
	for (int i = 0; i < r; i++) {
		Fraction nextV[6];
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 4; k++) {
				nextV[j] = nextV[j] + v[f[j][k]] / 4; 
			}
		}
		for (int j = 0; j < 6; j++) v[j] = nextV[j];
	}
	return v[2].format();
}
//Powered by [KawigiEdit] 2.0!
