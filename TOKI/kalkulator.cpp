#include <cstdio>
#include <cstring>
using namespace std;

const long long MOD=1000000LL;
int n;
long long memo[11][110000],sum;
long long dp(int x, int sisa){
    if(sisa){
            if(memo[x][sisa]) return memo[x][sisa];
            long long kom=0;
            if(x==0) kom=( 0 + dp(0, sisa-1) + dp(1, sisa-1) )%MOD; else
            if(x==1) kom=( 0 + dp(0, sisa-1) + dp(1, sisa-1) + dp(2, sisa-1) + dp(4, sisa-1) )%MOD; else
            if(x==2) kom=( 0 + dp(1, sisa-1) + dp(2, sisa-1) + dp(3, sisa-1) + dp(5, sisa-1) )%MOD; else
            if(x==3) kom=( 0 + dp(2, sisa-1) + dp(3, sisa-1) + dp(6, sisa-1)%MOD ); else
            if(x==4) kom=( 0 + dp(1, sisa-1) + dp(4, sisa-1) + dp(5, sisa-1) + dp(7, sisa-1) )%MOD; else
            if(x==5) kom=( 0 + dp(2, sisa-1) + dp(4, sisa-1) + dp(5, sisa-1) + dp(6, sisa-1) + dp(8, sisa-1) )%MOD; else
            if(x==6) kom=( 0 + dp(3, sisa-1) + dp(5, sisa-1) + dp(6, sisa-1) + dp(9, sisa-1) )%MOD; else
            if(x==7) kom=( 0 + dp(4, sisa-1) + dp(7, sisa-1) + dp(8, sisa-1) )%MOD; else
            if(x==8) kom=( 0 + dp(5, sisa-1) + dp(7, sisa-1) + dp(8, sisa-1) + dp(9, sisa-1) )%MOD; else
            if(x==9) kom=( 0 + dp(6, sisa-1) + dp(8, sisa-1) + dp(9, sisa-1) )%MOD;
            memo[x][sisa]=kom;
            return kom%MOD;
    }
    return 1;
}

int main(){
    scanf("%d", &n);
    dp(0,n/3);
    dp(0,(int)(0.6*n));
    sum=0;
    for(int i=0; i<10; i++)
        sum=sum+dp(i,n-1)%MOD;
    printf("%lld\n", sum%MOD);
    return 0;
}
