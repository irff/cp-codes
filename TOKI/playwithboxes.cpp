#include <cstdio>
using namespace std;

long long dp[100100],n;
int teskes;
int main(){
    dp[1]=1;
    for(long long i=2,j=1; i<100002; i++) dp[i]=(dp[i-1]*j)%1000000007LL,j+=i;
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%lld", &n);
        printf("%lld\n", dp[n]);
    }
    return 0;
}
