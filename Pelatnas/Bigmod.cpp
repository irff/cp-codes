#include <cstdio>

typedef long long LLD;

LLD a,b,c;

LLD pangkat(LLD a,LLD b, LLD c){
    if(b==0) return 1;
    LLD x=pangkat(a,b/2,c)%c;
    if(b%2==0) return x*x%c;
    return a*x*x%c;
}

int main(){
    scanf("%lld%lld%lld", &a,&b,&c);
    printf("%lld\n", pangkat(a,b,c));
    return 0;
}
