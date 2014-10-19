#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

char sa[1010], si[1010];
int lena = 0, leni = 0, memo[1010][1010];

int rek(int a, int b) {
    if(memo[a][b]==-1) {
        int x = lena-a, y = leni - b;

        if(x==0 or y==0) return 0;

        int maks = 0;

        if(sa[a]==si[b]) maks = max(maks, rek(a+1,b+1)+1);
        
        maks = max(maks, rek(a+1, b));
        maks = max(maks, rek(a, b+1));

        return memo[a][b] = maks;
    }
    return memo[a][b];
}
int main() {
    while(gets(sa) > 0 and gets(si) > 0) {
        lena = strlen(sa), leni = strlen(si);
        R(i,0,lena+2) R(j,0,leni+2) memo[i][j] = -1;
        int ans = rek(0,0);
        printf("%d\n", ans);
    }
    return 0;
}
