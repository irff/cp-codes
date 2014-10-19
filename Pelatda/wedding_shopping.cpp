#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int INF = 2000111222;

int teskes, n, duit, a[30][30], len[30], ans;
bool memo[30][400];
void rek(int ke, int duit) {
    if(!memo[ke][duit]) {
        memo[ke][duit] = 1;
        if(ke>=n) {
            if(duit >= 0) {
                ans = min(duit, ans);
            }
            return ;
        }
        R(i,0,len[ke]) {
            if(duit >= a[ke][i]) rek(ke+1, duit-a[ke][i]);
        }
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &duit, &n);
        ans = INF;
        memset(memo, 0, sizeof memo);
        R(i,0,n) {
            scanf("%d", &len[i]);
            R(j,0,len[i]) {
                scanf("%d", &a[i][j]);
            }
        }
        rek(0, duit);
        if(ans == INF) {
            printf("no solution\n");
        } else {
            printf("%d\n", duit-ans);
        }
    
    }

    return 0;
}
