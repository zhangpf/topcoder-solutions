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

class WhatSort {
	struct Person {
		string name;
		int age;
		int wt;
	};
	int n;
	static int cmpNAW(const Person &p1, const Person &p2) {
		if (p1.name != p2.name) return p1.name < p2.name;
		if (p1.age != p2.age) return p1.age < p2.age;
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		return 1;
	}
	static int cmpNWA(const Person &p1, const Person &p2) {
		if (p1.name != p2.name) return p1.name < p2.name;
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		if (p1.age != p2.age) return p1.age < p2.age;
		return 1;
	}
	static int cmpANW(const Person &p1, const Person &p2) {
		if (p1.age != p2.age) return p1.age < p2.age;
		if (p1.name != p2.name) return p1.name < p2.name;
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		return 1;
	}
	static int cmpWAN(const Person &p1, const Person &p2) {
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		if (p1.age != p2.age) return p1.age < p2.age;
		if (p1.name != p2.name) return p1.name < p2.name;
		return 1;
	}
	static int cmpAWN(const Person &p1, const Person &p2) {
		if (p1.age != p2.age) return p1.age < p2.age;
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		if (p1.name != p2.name) return p1.name < p2.name;
		return 1;
	}
	static int cmpWNA(const Person &p1, const Person &p2) {
		if (p1.wt != p2.wt) return p1.wt > p2.wt;
		if (p1.name != p2.name) return p1.name < p2.name;
		if (p1.age != p2.age) return p1.age < p2.age;
		return 1;
	}
	vector<Person> t;
	void check(int &x, int y, int cmp(const Person &p1, const Person &p2)) {
		if (x == -2) return;
 		for (int i = 1; i < t.size(); i ++) {
			if (!cmp(t[i - 1], t[i])) return;
		}
		if (x == -1) x = y;
		else x = -2;
	}
public:
	string sortType(vector <string>, vector <int>, vector <int>);
};

const string funName[6] = {"NAW", "NWA", "ANW", "AWN", "WAN", "WNA"};

string WhatSort::sortType(vector <string> name, vector <int> age, vector <int> wt) {
	n = name.size();
	t.resize(n);
	for (int i = 0; i < n; i ++) {
		t[i].name = name[i];
		t[i].age = age[i];
		t[i].wt = wt[i];
	}
	int ch = -1;
	check(ch, 0, cmpNAW);
	check(ch, 1, cmpNWA);
	check(ch, 2, cmpANW);
	check(ch, 3, cmpAWN);
	check(ch, 4, cmpWAN);
	check(ch, 5, cmpWNA);
	if (ch == -2) return "IND";
	if (ch == -1) return "NOT";
	return funName[ch];
}
//Powered by [KawigiEdit] 2.0!
