#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int nbarang, total = 0, fibo[100], ncoin = 2;
LLD dp[5000];
int main() {
    fibo[0] = 1;
    fibo[1] = 2;
    for(int i=2; i<17; i++) {
        fibo[i] = fibo[i-1]+fibo[i-2];
        ncoin++;
        //printf("%d\n", fibo[i]);
    }
    scanf("%d", &nbarang);
    R(i,0,nbarang) {
        int n;
        scanf("%d", &n); total+=n;
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        R(j,0,ncoin) {
            R(k,1,n+1) {
                if(k-fibo[j] >= 0) dp[k] += dp[k-fibo[j]];
            }
        }
        printf("%lld\n", dp[n]);
    }
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    R(i,0,ncoin) {
        R(j,1,total+1) {
            if(j-fibo[i] >= 0) dp[j] += dp[j-fibo[i]];
        }
    }
    printf("%lld\n", dp[total]);
    return 0;
}
