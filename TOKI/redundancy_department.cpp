#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int ord[3000111], ctr = 0;
map<int,int> m;
int main() {
    int n;
    while(scanf("%d", &n) > 0) {
        if(m[n]==0) { ord[ctr++] = n;}
        m[n]++;
    }
    R(i,0,ctr) printf("%d %d\n", ord[i], m[ ord[i] ]);
    return 0;
}
