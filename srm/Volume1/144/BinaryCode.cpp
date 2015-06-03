#line 5 "BinaryCode.cpp"
#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class BinaryCode {
	public:
	vector <string> decode(string message) {
		string ans1 = "0";
		int n = message.size();
		int ok1 = 1;
		for (int i = 0; ok1 && i < n; i++) {
			int k = message[i] - '0';
			if (i >= 0) k -= ans1[i] - '0';
			if (i-1 >= 0) k -= ans1[i-1] - '0';
			if (i != n-1 && (k == 0 || k == 1)) {
				ans1 += (k + '0');
			} else if (i != n-1) ok1 = 0;
			if (i == n-1 && k != 0) ok1 = 0;
		}
		string ans2 = "1";
		int ok2 = 1;
		for (int i = 0; ok2 && i < n; i++) {
			int k = message[i] - '0';
			if (i >= 0) k -= ans2[i] - '0';
			if (i-1 >= 0) k -= ans2[i-1] - '0';
			if (i != n-1 && (k == 0 || k == 1)) {
				ans2 += (k + '0');
			} else if (i != n-1) ok2 = 0;
			if (i == n-1 && k != 0) ok2 = 0;
		}
		vector<string> ret;
		if (!ok1) ret.push_back("NONE");
		else ret.push_back(ans1);
		if (!ok2) ret.push_back("NONE");
		else ret.push_back(ans2);
		return ret;
	}
};


// Powered by FileEdit