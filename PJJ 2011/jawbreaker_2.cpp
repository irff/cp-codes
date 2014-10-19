#include <algorithm>
#include <cstdio>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int bar, kol, m[100][100], nilai=0, now = 0, maks = 0;

void dfs(int a, int b) {
    if( a >= 0 and a<bar and b>=0 and b<kol and m[a][b]==now) {
        nilai++;
        m[a][b] = 0;
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d%d", &bar, &kol);
    R(i,0,bar) R(j,0,kol) scanf("%d", &m[i][j]);
    R(i,0,bar) R(j,0,kol) {
        if(m[i][j] != 0) {
            nilai = 0;
            now = m[i][j];
            dfs(i,j);
            maks = max(nilai,maks);
        }
    }
    printf("%d\n",maks*(maks-1));
    return 0;
}
