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
#include <cstring>
#include <memory>
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

class FoxAndSouvenirTheNext {
	int ans[30][2000];
public:
    string ableToSplit(vector <int> value) {
		int n = value.size(), sum = 0;
		for (int i = 0; i < n; i ++) sum += value[i];
		if (n % 2 || sum % 2) return "Impossible";
		int m = sum / 2, h = n / 2;
		memset(ans, 0, sizeof(ans));
    	ans[0][0] = 1;
		for (int i = 0; i < n; i ++) {
			for (int k = 0; k < h; k ++)
				for (int j = m - value[i]; j >= 0; j --) if(ans[k][j]) {
					ans[k + 1][j + value[i]] = 1;
				}
		}
		if (!ans[h][m]) return "Impossible";
		return "Possible";
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
        int valueARRAY[] = {1,2,3,4};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(0, theObject.ableToSplit(value),"Possible");
    }
    {
        int valueARRAY[] = {1,1,1,3};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(1, theObject.ableToSplit(value),"Impossible");
    }
    {
        int valueARRAY[] = {1,1,2,3,5,8};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(2, theObject.ableToSplit(value),"Possible");
    }
    {
        int valueARRAY[] = {2,3,5,7,11,13};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(3, theObject.ableToSplit(value),"Impossible");
    }
    {
        int valueARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(4, theObject.ableToSplit(value),"Possible");
    }
    {
        int valueARRAY[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
        vector <int> value( valueARRAY, valueARRAY+ARRSIZE(valueARRAY) );
        FoxAndSouvenirTheNext theObject;
        eq(5, theObject.ableToSplit(value),"Impossible");
    }
}
// END CUT HERE
