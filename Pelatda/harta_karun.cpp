#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;
int bar, kol, harta, jarak, m[200][200], now = 0, maks = -1, luas = 0, kar = 0;

void fill(int a, int b) {
    R(i,0,bar) R(j,0,kol) {
        int dist = abs(i-a)+abs(j-b);
        if(dist !=0 and dist <= jarak and m[i][j]!=INF) m[i][j]++;
    }
    m[a][b] = INF;
}

void dfs(int a, int b) {
    if(a >= 0 and a < bar and b >= 0 and b < kol and m[a][b]==now) {
        luas++;
        m[a][b] = -1;
        dfs(a-1,b);
        dfs(a,b+1);
        dfs(a+1,b);
        dfs(a,b-1);
    }
}

int main() {
    scanf("%d%d%d%d", &bar, &kol, &harta, &jarak);
    R(i,0,harta) {
        int a, b;
        scanf("%d%d", &b, &a);
        fill(a-1,b-1);
    }
    R(i,0,bar) {
      R(j,0,kol) {
        if(m[i][j]==INF) printf("S");
        else printf("%d", m[i][j]);
        printf("%c", j==kol-1?'\n':' ');
      }
    }
    R(i,0,bar) {
        R(j,0,kol) {
            if(m[i][j]!=-1) {
                now = m[i][j];
                luas = 0;
                dfs(i,j);
                if( luas > maks) {
                    maks = luas;
                    kar  = now;
                }
            }
        }
    }
    printf("%d ", maks);
    if(kar==INF) printf("S\n");
    else printf("%d\n", kar);
    return 0;
}
