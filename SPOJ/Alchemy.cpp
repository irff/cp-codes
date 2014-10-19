#include <cstdio>
#define MOD 1000000007
int n,teskes;

typedef long long LLD;


LLD itung(int n){
    LLD p=1LL;
    LLD a=2LL,b=n;
    while(b!=0LL){
        if(b%2LL) b--,p=(p%MOD*a%MOD)%MOD;
        else b/=2LL,a=(a%MOD*a%MOD)%MOD;
    }
    p+=MOD;
    LLD x=((n*(n-1LL)/2LL)+1LL+n)%MOD;
    p-=x;
    return p;
}

int main(){
    scanf("%d", &teskes);
    while(teskes--){
        scanf("%d", &n);
        printf("%lld\n", itung(n)%MOD);
    }

    return 0;
}
