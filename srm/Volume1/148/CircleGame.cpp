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

class CircleGame {
	int decode(char c) {
		if (c == 'A') return 1;
		if (c >= '2' && c <= '9') return c - '0';
		if (c == 'T') return 10;
		if (c == 'J') return 11;
		if (c == 'Q') return 12;
		return 13;
	}
	int check(char c1, char c2) {
		return decode(c1) + decode(c2) == 13;
	}
public:
	int cardsLeft(string);
};

int CircleGame::cardsLeft(string deck) {
	int ok = 1;
	while (ok && deck.size()) {
		ok = 0;
		int n = deck.size();
		for (int i = 0; !ok && i < n; i ++) {
			if (deck[0] == 'K') {
				ok = 1; 
				deck = deck.substr(1);
				break;
			} else if (deck.length() >= 2 && check(deck[0], deck[1])) {
				ok = 1;
				deck = deck.substr(2);
				break;
			}
			deck = deck.substr(1) + deck[0];
		}
	}
	return deck.size();
}

//Powered by [KawigiEdit] 2.0!
