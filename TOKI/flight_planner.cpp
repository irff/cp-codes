#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)


int teskes;
int dp[12][1200], m[12][1200];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int len;
        scanf("%d", &len);
        len/=100;
        RV(i,9,0) 
          R(j,0,len)
            scanf("%d", &m[i][j]);
        R(i,0,10) R(j,0,len+1) dp[i][j] = 200111;
        dp[0][0] = 0;
        R(j,0,len) {
            R(i,0,10) {
                if(i<9) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+(60-m[i][j]));
                        dp[i][j+1]   = min(dp[i  ][j+1], dp[                    i][j]+(30-m[i][j]));
                if(i>0) dp[i-1][j+1] = min(dp[i-1][j+1], dp[i][j]+(20-m[i][j]));
            }
        }
        /*
        RV(i,9,0) {
          R(j,0,len+1) {
              if(dp[i][j]==99999) printf("X ");
              else printf("%d ", dp[i][j]);
          }
          printf("\n");
        }
        */
        printf("%d\n\n", dp[0][len]);
    }

    return 0;
}
