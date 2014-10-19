#include <cstdio>
using namespace std;

typedef long long LLD;

LLD pangkat(LLD a, LLD b){
    if( b == 0 ) return 1;
    LLD x=pangkat(a,b/2);
    if(b%2) return a*x*x;
    return x*x;
}

LLD a,b;

int main(){
    scanf("%lld%lld", &a,&b);
    printf("%lld\n", pangkat(a,b)%9);
    scanf("\n");
    return 0;
}
