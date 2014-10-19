#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <iostream>
#include <string>
#include <map>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define fi first
#define se second
#define mp make_pair
#define vi vector<int>
#define pb push_back
#define MAX 2147483647
#define INF 1000000000
#define EPS 1e-9

int n, q, p[1000001], r[1000001], sny=0, bbs, a, b;

int fs(int x) { return (p[x] == x) ? x : (p[x] = fs(p[x])); }

char s[10];

int main() {
	scanf("%d %d", &n, &q);
	bbs = n;
	for (int i=n;i;i--) {
		p[i] = i;
		r[i] = 1;
	}
	while (q--) {
		scanf("%s", s);
		if (s[0] == 'G') {
			scanf("%d %d", &a, &b);
			int x = fs(a), y = fs(b);
			if (x != y) {
				if (r[x]==1) bbs--;
				if (r[y]==1) bbs--;
				if (r[x]==1 && r[y]==1) sny++;
				else if (!(r[x]==1 || r[y]==1)) sny--;

				if (r[x] > r[y]) {
				    	p[y] = p[x];
					    r[x] += r[y];
				    } else {
					    p[x] = p[y];
					    r[y] += r[x];
				    }
			    }
			    
		} else if (s[1] == '1') {
			printf("%d\n", sny);
		} else if (s[1] == '2') {
			printf("%d\n", bbs);
		} else if (s[1] == '3') {
			scanf("%d", &a);
			printf("%d\n", r[fs(a)]);
		} else scanf("%d", &a);
	}
	return 0;
}
