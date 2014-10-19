#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes,n, maks, xa,ya, xi,yi, npion;
bool pion[30][30];
int memo[20][30][30];

int rek(int ke, int a, int b) {
    if(!memo[ke][a][b]) {
        if(ke>=maks) {
            if(pion[a][b]) return 1;
            return 0;
        }
        int hasil = 0;
        hasil+=rek(ke+1, a-1, b-2);
        hasil+=rek(ke+1, a-2, b-1);
    
        hasil+=rek(ke+1, a-1, b+2);
        hasil+=rek(ke+1, a-2, b+1);
    
        hasil+=rek(ke+1, a+1, b+2);
        hasil+=rek(ke+1, a+2, b+1);
    
        hasil+=rek(ke+1, a+1, b-2);
        hasil+=rek(ke+1, a+2, b-1);
        return memo[ke][a][b] = hasil;
    }
    return memo[ke][a][b];
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d%d%d%d", &n, &maks, &xa, &ya, &xi, &yi);
        scanf("%d", &npion);
        R(i,0,npion) {
            int na, ni;
            scanf("%d%d", &na, &ni);
            pion[na][ni] = 1;
        }
        int puguh = rek(0,xa,ya);
        memset(memo,0,sizeof memo);
        int yongkru = rek(0,xi,yi);
        //printf("%d %d\n", puguh, yongkru);
        if(puguh > yongkru) printf("PUGUH\n");
        else if(yongkru > puguh) printf("Yongkru\n");
        else printf("SERI\n");
    }
    return 0;
}
