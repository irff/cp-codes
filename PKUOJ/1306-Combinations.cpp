#include <cstdio>
#include <algorithm>
using namespace std;

long long binomial(int n, int k){
    long long c[200][200];
    memset(c, 0, sizeof c);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=min(i,k); j++)
         if( j == 0 or j == i) 
             c[i][j]=1;
         else c[i][j]=c[i-1][j-1]+c[i-1][j];
    return c[n][k];
}

int main(){
    int n,k;
    scanf("%d%d", &n, &k);
    while(n!=0 or k!=0){
        printf("%d things taken %d at a time is %lld exactly.\n", n,k,binomial(n,k));
        scanf("%d%d", &n, &k);
    }
    return 0;
}
