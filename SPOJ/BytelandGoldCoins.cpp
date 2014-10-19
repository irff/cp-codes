#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LLD;

LLD memo[2000111];
LLD rek(LLD n){
    if(n==0) return 0;
    if(n<2000000) if(memo[n]) return memo[n];
    LLD a=rek((n/2LL));
    LLD b=rek((n/3LL));
    LLD c=rek((n/4LL));
    return max(n,a+b+c);
}

int main(){
    for(int i=0; i<2000000; i++){
        memo[i]=max((LLD)i,memo[i/2]+memo[i/3]+memo[i/4]);
        //printf("%lld\n", memo[i]);
    }
    long long n,x;
    while(scanf("%lld", &n)>0){
        printf("%lld\n", rek(n));
    }
}
