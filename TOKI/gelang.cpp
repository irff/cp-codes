#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

long long dp[100000];
int teskes,n,maks,berat[20000],cost[20000];
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        memset(dp,0,sizeof dp);
        memset(berat,0,sizeof berat);
        memset(cost,0,sizeof cost);
        scanf("%d%d", &n,&maks);
        R(i,1,n+1) scanf("%d%d", &berat[i],&cost[i]);
        R(i,1,n+1)
            RV(j,maks,berat[i]) dp[j]=max( dp[j], dp[j-berat[i]]+cost[i]);
        printf("%lld\n", dp[maks]);
    }
    return 0;
}
