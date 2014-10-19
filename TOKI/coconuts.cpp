#include <cstdio>
#include <cstring>
#include <cmath>
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int m;
int main() {
    while(scanf("%d", &m) && m>=0) {
        int hi = sqrt(m)+1; bool found = 0;
        int p = hi;
        for( ; p>=2 && !found; p--) {
            int n = m, i = 0;
            for(; i<p && n%p==1; i++) {
                n-=(n/p+1);
            }
            if(i==p && n%p==0) {
                found = 1;
                break;
            }
        }
        if(found) printf("%d coconuts, %d people and 1 monkey\n", m, p);
        else printf("%d coconuts, no solution\n", m);
    }
    return 0;
}
