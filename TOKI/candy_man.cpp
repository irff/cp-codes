#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int INF = 2000111222;

int teskes, n, ans = INF;
int a[34], total;
bool memo[34][650][650];

void rek(int ke, int x, int y) {
    //  printf("%d %d %d\n", ke, x, y);
    if(ke>=n) {
        int z = total-x-y;
        ans = min(ans, max(x,max(y,z)) - min(x,min(y,z)));
        return ;
    }
    if(!memo[ke][x][y]) {
        memo[ke][x][y] = 1;
        rek(ke+1, x+a[ke], y);
        rek(ke+1, x, y+a[ke]);
        rek(ke+1, x, y);
    } 
}

int main() {
    scanf("%d", &teskes);
    R(kasus,0,teskes) {
        total = 0, ans = INF;
        scanf("%d", &n);
        R(i,0,n) {
            scanf("%d", &a[i]);
            total+=a[i];
        }
        R(i,0,n+2) R(j,0,total+2) R(k,0,total+2)
            memo[i][j][k] = 0;
        rek(0,0,0);
        printf("Case %d: %d\n", kasus+1, ans);
    } 
    return 0;
}
