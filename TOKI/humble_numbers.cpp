#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


set<int> vis;
int n, k, p[120];

void rek(int a) {
    if(vis.count(a)) return ;
}

int main() {
	scanf("%d%d", &n, &k);
	R(i,0,n) scanf("%d", &p[i]);
	rek(1);
    return 0;
}
