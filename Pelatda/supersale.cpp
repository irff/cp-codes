#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, nbarang, norang, v[1200], w[1200], kap;

int knap(int ke, int sisa) {
    if(sisa <= 0) return 0;
    if(ke >= nbarang) return 0;
    
    int ret = 0;
    if(sisa - w[ke] >=0) ret=knap(ke+1, sisa-w[ke]);
    ret=max(ret, knap(ke+1, sisa));
    return ret;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &nbarang);
        R(i,0,nbarang) scanf("%d%d", &v[i], &w[i]);
        scanf("%d", &norang);
        int maks = 0;
        R(i,0,norang) {
            scanf("%d", &kap);
            maks+=knap(0, kap);
        }
        printf("%d\n", maks);
    }
    return 0;
}
