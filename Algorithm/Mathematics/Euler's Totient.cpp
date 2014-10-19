#include <cstdio>
typedef long long LLD;

LLD n;
LLD euler(LLD n){
    LLD result=n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0) result-=result/i;
        while(n%i==0) n/=i;
    }
    if( n > 1 ) result-=(LLD)(double)result/n;
    return result;
}

int main(){
    scanf("%lld", &n);
    printf("%lld\n", euler(n));
    scanf("\n");
}
