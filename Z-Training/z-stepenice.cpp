#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD=1021987;

long long binomial(int n, int k){
    long long c[n+1][k+1];
    memset(c, 0, sizeof c);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=min(i,k); j++)
         if( j == 0 or j == i) 
             c[i][j]=1;
         else c[i][j]=c[i-1][j-1]+c[i-1][j]%MOD;
    return c[n][k];
}

int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    printf("%lld\n", binomial(n,k));
    
    scanf("\n");
    return 0;
}
