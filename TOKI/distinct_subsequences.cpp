#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes, lena, leni;
char sa[12000], si[120];
LLD memo[10002][102];

LLD rek(int a, int b) {
    if(b >= leni) return 1;
    if(a >= lena) return 0;
    if(memo[a][b]!=-1) return memo[a][b];
    
    LLD ans = 0;
    if(lena-a >= leni-b and sa[a] == si[b]) ans +=rek(a+1,b+1);
    if(lena-a-1 >= leni - b) ans+=rek(a+1,b);
    return memo[a][b] = ans;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        LLD ans = 0;
        scanf("%s", &sa);
        scanf("%s", &si);
        lena = strlen(sa), leni = strlen(si);
        R(i,0,lena+1) R(j,0,leni+1) memo[i][j] = -1;
        ans = rek(0,0);
        printf("%lld\n", ans);
    }
    return 0;
}
