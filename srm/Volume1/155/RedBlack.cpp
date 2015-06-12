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
#include <memory>
#include <cstring>
#include <ctime>

using namespace std;
const int maxn = 110;

class RedBlack {
	struct node {
		node *p, *l, *r; 
		int c;
		int v;
	}t[maxn];
	int sz;
	void twist(node * cur) {
		//printf("twist = %d\n", cur->v);
		if (cur->c == 1) return;
		if (cur->p == NULL) {
			root = cur;
			cur->c = 1;
			return;
		} 
		if (cur->p->c == 1) return;
		cnt ++;
		node * pa = cur->p;
		node * gpa = cur->p->p;
		if (pa->l == cur && gpa->l == pa) {
			if (gpa->p != NULL) {
				if (gpa->p->r == gpa) {
					gpa->p->r = pa;
				} else gpa->p->l = pa;
			}
			pa->p = gpa->p;
			if(pa->r != NULL) 
				pa->r->p = gpa; 
			gpa->l = pa->r;
			pa->l = cur; pa->r = gpa;
			gpa->p = cur->p = pa;
			cur->c = 1; gpa->c = 1; pa->c = 0;
			twist(pa);
		} else if (pa->r == cur && gpa->r == pa) {
			if (gpa->p != NULL) {
				if (gpa->p->r == gpa) {
					gpa->p->r = pa;
				} else gpa->p->l = pa;
			}
			pa->p = gpa->p;
			if(pa->l != NULL) pa->l->p = gpa; 
			gpa->r = pa->l;
			pa->r = cur; pa->l = gpa;
			gpa->p = cur->p = pa;
			cur->c = 1; gpa->c = 1; pa->c = 0;
			twist(pa);
		} else if (pa->r == cur && gpa->l == pa){
			if (gpa->p != NULL) {
				if (gpa->p->r == gpa) {
					gpa->p->r = cur;
				} else gpa->p->l = cur;
			}
			cur->p = gpa->p;
			if (cur->l != NULL) 
				cur->l->p = pa; 
			pa->r = cur->l;
			if (cur->r != NULL) 
				cur->r->p = gpa; 
			gpa->l = cur->r;
			cur->l = pa; cur->r = gpa;
			gpa->p = pa->p = cur;
			cur->c = 0; gpa->c = 1; pa->c = 1;
			twist(cur);
		} else if (pa->l == cur && gpa->r == pa) {
			if (gpa->p != NULL) {
				if (gpa->p->r == gpa) {
					gpa->p->r = cur;
				} else gpa->p->l = cur;
			}
			cur->p = gpa->p;
			if (cur->l != NULL)
				cur->l->p = gpa; 
			gpa->r = cur->l;
			if (cur->r != NULL) 
				cur->r->p = pa; 
			pa->l = cur->r;
			cur->l = gpa; cur->r = pa;
			gpa->p = pa->p = cur;
			cur->c = 0; gpa->c = 1; pa->c = 1;
			twist(cur);
		}
	}
	
	void insert(node *cur, int v) {
		if (cur->v < v && cur->r != NULL) {
			insert(cur->r, v);
		} else if (cur->v > v && cur->l != NULL) {
			insert(cur->l, v);
		} else if (cur->v > v) {
			t[sz].v = v;
			t[sz].p = cur;
			cur->l = &t[sz];
			t[sz].c = 0;
			twist(&t[sz]);
			sz ++;
		}  else {
			t[sz].v = v;
			t[sz].p = cur;
			cur->r = &t[sz];
			t[sz].c = 0;
			twist(&t[sz]);
			sz ++;
		}	
	}
	void traverse(node * cur) {
		if (cur->l != NULL) traverse(cur->l);
		printf("%d\n", cur ->v);
		if (cur->r != NULL) traverse(cur->r);
	}
	node * root;
	int cnt;
public:
	int numTwists(vector <int>);
};

int RedBlack::numTwists(vector <int> keys) {
	cnt = 0;
	sz = 1;
	memset(t, 0, sizeof(t));
	root = &t[0];
	t[0].c = 1;
	t[0].v = keys[0];
	for (int i = 1; i < keys.size(); i ++) {
		insert(root, keys[i]);
		//traverse(root);
		//puts("");
	}
	return cnt;
}

//Powered by [KawigiEdit] 2.0!
