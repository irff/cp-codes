#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef unsigned long long LLD;

int n[4];
LLD dp[302][302], sum[302][302];
char s[100];
int main() {
    dp[0][0] = 1;
    R(i,1,301) {
      R(j,i,301) {
        R(k,1,301) {
            dp[j][k]+=dp[j-i][k-1];
        }
      }
    }
    R(i,0,301) sum[0][i] = dp[i][0];
    R(i,0,301) {
      R(j,1,301) {
        sum[i][j] = dp[i][j]+sum[i][j-1];
      }
    }
    while(gets(s) > 0) {
        int tokens, i, j, k;
        tokens=sscanf(s,"%d %d %d",&i,&j,&k);
        
        if(tokens==1)
            printf("%llu\n",sum[i][i]);
        else if(tokens==2)
            printf("%llu\n",sum[i][min(j,i)]);
        else if(j<=i)
            printf("%llu\n",sum[i][min(k,i)]-sum[i][j]+dp[i][j]);
        else puts("0");
        
    }
    return 0;
}
