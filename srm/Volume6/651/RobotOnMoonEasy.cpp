// BEGIN CUT HERE

// END CUT HERE
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
using namespace std;

vector<string> split( const string& s, const string& delim =" " ) {
    vector<string> res;
    string t;
    for ( int i = 0 ; i != s.size() ; i++ ) {
        if ( delim.find( s[i] ) != string::npos ) {
            if ( !t.empty() ) {
                res.push_back( t );
                t = "";
            }
        } else {
            t += s[i];
        }
    }
    if ( !t.empty() ) {
        res.push_back(t);
    }
    return res;
}

vector<int> splitInt( const string& s, const string& delim =" " ) {
    vector<string> tok = split( s, delim );
    vector<int> res;
    for ( int i = 0 ; i != tok.size(); i++ )
        res.push_back( atoi( tok[i].c_str() ) );
    return res;
}

const int ox[4] = {-1, 0, 0, 1};
const int oy[4] = {0, -1, 1, 0};

class RobotOnMoonEasy {
	int parse(char c) {
		if (c == 'U') return 0;
		else if (c == 'L') return 1;
		else if (c == 'R') return 2;
		return 3;
	}
public:
    string isSafeCommand(vector <string> board, string S) {
		int sx = 0, sy = 0;
		int n = board.size(), m = board[0].length();
        for (int i = 0; i < n; i ++) {
        	for (int j = 0; j < m; j ++) {
				if (board[i][j] == 'S') {
        			sx = i; sy = j;
				}
        	} 
        }
		int ok = 1, now = 0;
		while (ok && now < S.length()) {
			int k = parse(S[now ++]);
			sx = sx + ox[k];
			sy = sy + oy[k];
			if (sx < 0 || sx >= n || sy < 0 || sy >= m) ok = 0;
			else if (board[sx][sy] == '#') {
				sx -= ox[k];
				sy -= oy[k];
			}
		}
        if (!ok) return "Dead";
		else return "Alive";
    }

};

// BEGIN CUT HERE
#define ARRSIZE(x) (sizeof(x)/sizeof(x[0]))

template<typename T> void print( T a ) {
    cerr << a;
}
static void print( long long a ) {
    cerr << a << "L";
}
static void print( string a ) {
    cerr << '"' << a << '"';
}
template<typename T> void print( vector<T> a ) {
    cerr << "{";
    for ( int i = 0 ; i != a.size() ; i++ ) {
        if ( i != 0 ) cerr << ", ";
        print( a[i] );
    }
    cerr << "}" << endl;
}
template<typename T> void eq( int n, T have, T need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
template<typename T> void eq( int n, vector<T> have, vector<T> need ) {
    if( have.size() != need.size() ) {
        cerr << "Case " << n << " failed: returned " << have.size() << " elements; expected " << need.size() << " elements.";
        print( have );
        print( need );
        return;
    }
    for( int i= 0; i < have.size(); i++ ) {
        if( have[i] != need[i] ) {
            cerr << "Case " << n << " failed. Expected and returned array differ in position " << i << ".";
            print( have );
            print( need );
            return;
        }
    }
    cerr << "Case " << n << " passed." << endl;
}
static void eq( int n, string have, string need ) {
    if ( have == need ) {
        cerr << "Case " << n << " passed." << endl;
    } else {
        cerr << "Case " << n << " failed: expected ";
        print( need );
        cerr << " received ";
        print( have );
        cerr << "." << endl;
    }
}
// END CUT HERE
// BEGIN CUT HERE
int main( int argc, char* argv[] ) {
    {
        string boardARRAY[] = {".....",
            ".###.",
            "..S#.",
            "...#."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(0, theObject.isSafeCommand(board, "URURURURUR"),"Alive");
    }
    {
        string boardARRAY[] = {".....",
            ".###.",
            "..S..",
            "...#."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(1, theObject.isSafeCommand(board, "URURURURUR"),"Dead");
    }
    {
        string boardARRAY[] = {".....",
            ".###.",
            "..S..",
            "...#."};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(2, theObject.isSafeCommand(board, "URURU"),"Alive");
    }
    {
        string boardARRAY[] = {"#####",
            "#...#",
            "#.S.#",
            "#...#",
            "#####"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(3, theObject.isSafeCommand(board, "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"),"Alive");
    }
    {
        string boardARRAY[] = {"#####",
            "#...#",
            "#.S.#",
            "#...#",
            "#.###"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(4, theObject.isSafeCommand(board, "DRULURLDRULRUDLRULDLRULDRLURLUUUURRRRDDLLDD"),"Dead");
    }
    {
        string boardARRAY[] = {"S"};
        vector <string> board( boardARRAY, boardARRAY+ARRSIZE(boardARRAY) );
        RobotOnMoonEasy theObject;
        eq(5, theObject.isSafeCommand(board, "R"),"Dead");
    }
}
// END CUT HERE
