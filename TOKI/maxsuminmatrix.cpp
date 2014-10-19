#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int a[101][11],sum,maks,bar,kol,teskes,s,dp[101][11][101];
int rek(int b, int k, int s){
    if(b>=bar) return 0;
    if(dp[b][k][s]) return dp[b][k][s];
    int maks=-1;
    int ret;
    for(int i=0; i<kol; i++){
        if(i!=k and s > 0) ret=rek(b+1,i,s-1)+a[b][k];
        else ret=rek(b+1, k, s)+a[b][k];
        maks=max(maks,ret);
    }
    return dp[b][k][s]=maks;
}
int main(){
    scanf("%d", &teskes);
    while(teskes--){
        memset(a,0,sizeof a);
        memset(dp, 0, sizeof dp);
        sum=0;
        scanf("%d%d%d", &bar,&kol,&s);
        for(int i=0; i<bar; i++)
         for(int j=0; j<kol; j++)
          scanf("%d", &a[i][j]);
         for(int i=0; i<kol; i++)
            sum=max(rek(0,i,s),sum);
        printf("%d\n", sum);
    }
    return 0;
}
