#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int len, n, a[20][2], awalx, awaly, akhirx, akhiry;
bool bisa = 0;
bool vis[20][2][16500];
void rek(int p, int x, int y, int dp) {
    //printf("%d %d\n", p, a[x][y]);
    if(vis[x][y][dp] or bisa) return ;
    vis[x][y][dp] = 1;
    if(p>=len) {
        if(a[x][y]==a[1][0]) bisa = 1;
        return ;
    }
    R(i,2,n+2) {
        if(!(dp&(1<<i))) {
            if(a[i][0]==a[x][y]) rek(p+1, i, 1, dp|(1<<i));
            if(a[i][1]==a[x][y]) rek(p+1, i, 0, dp|(1<<i));
        }
    }
}

int main() {
    while(scanf("%d", &len) and len) {
        bisa = 0;
        scanf("%d", &n);
        scanf("%d%d%d%d", &a[0][0], &a[0][1], &a[1][0], &a[1][1]);
        R(i,2,n+2) {
            scanf("%d%d", &a[i][0], &a[i][1]);
        }
        memset(vis, 0, sizeof vis);
        //printf("\n---\n");
        //rek(0, 0, 0, 0);
        //printf("\n---\n");
        rek(0, 0, 1, 0);
        if(bisa) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
