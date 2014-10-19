#include <cstdio>

typedef long long LLD;

LLD a,b,c,hasil;

LLD pangkat(LLD a, LLD b, LLD c) {
    if(b==0) return 1;
    LLD x=pangkat(a,b/2,c)%c;
    if(b%2==0) return x*x%c;
    return (a%c*x%c*x%c)%c;
} 

int main() {
    scanf("%lld%lld%lld", &a,&b,&c);
    hasil=pangkat(a,b,c);
    printf("%lld\n", hasil);
    return 0;
}
