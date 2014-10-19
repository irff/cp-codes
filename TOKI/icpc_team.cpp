#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

int teskes, n;
int a[6][13], now, ans = 0;
bool memo[5][282][4100];

void rek(int ke, int tadi, int sisa, int dp) {
    ans = max(ans, ke);
    if(!memo[tadi][sisa][dp]) {
        memo[tadi][sisa][dp] = 1;
        /*
        R(j,0,n) printf("%d", dp&(1<<j)!=0);
        printf("\n");
        */
        R(i,0,3) {
            R(j,0,n) {
                if(i!=tadi && sisa>=a[i][j] && !(dp&(1<<j))) {
                    rek(ke+1, i, sisa-a[i][j], dp|(1<<j));
                }
            }
        }
    }
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        ans = 0;
        scanf("%d", &n);
        R(i,0,3) {
            R(j,0,n) {
                scanf("%d", &a[i][j]);
            }
        }
        R(i,0,4) R(j,0,281) R(k,0,(1<<(n+1))) memo[i][j][k] = 0 ;
        
        rek(0,3,280,0);
        printf("%d\n", ans);
    }
    return 0;    
}
