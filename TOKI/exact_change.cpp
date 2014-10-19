#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int INF = 2000111222;

int teskes, duit, n, coin[120], cc[10111];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &duit, &n);
        R(i,0,n) {
            scanf("%d", &coin[i]);
        }
        R(i,1,10111) cc[i] = INF;
        cc[0] = 0;
        R(i,0,n) {
            RV(j,10111,coin[i]) {
                cc[j] = min(cc[j], cc[j-coin[i]]+1);
            }
        }
        R(i,duit,32000) {
            if(cc[i]<INF) {
                printf("%d %d\n", i, cc[i]);
                break;
            }
        }
    }
    return 0;
}
