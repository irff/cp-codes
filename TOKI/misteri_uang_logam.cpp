#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111;

int nlogam, nkertas, duit;
int memo[100111][2];
int logam[20], kertas[20], ans = 2000111222;
int rek(int sisa, bool ganjil) {
    if(!memo[sisa][ganjil]) {
        if(sisa == 0) {
            if(ganjil) return INF;
            return 0;
        }
        int mins = INF;
        R(i,0,nlogam) {
            if(sisa - logam[i] >=0) mins = min(mins, rek(sisa-logam[i], 1-ganjil)+1);
        }
        R(i,0,nkertas) {
            if(sisa - kertas[i] >=0) mins = min(mins, rek(sisa-kertas[i], ganjil)+1);
        }
        return memo[sisa][ganjil] = mins;
    }
    return memo[sisa][ganjil];
}

int main() {
    scanf("%d%d%d", &duit, &nlogam, &nkertas);
    R(i,0,nlogam) scanf("%d", &logam[i]);
    R(i,0,nkertas) scanf("%d", &kertas[i]);
    ans = rek(duit, 0);
    if(ans > 2000000) printf("-1\n");
    else printf("%d\n", ans);
    return 0;
}
