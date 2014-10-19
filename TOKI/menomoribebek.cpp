#include <cstdio>
#include <cmath>
using namespace std;
long long a,b,da,db,dc;
long long Bismillah(long long b){
     long long x=10,n=0;
     while(1){
         if(b>=x) n+=(x-(x/10))*(long long)floor(log10(x));
         else {
             n+=(b-(x/10))*(long long)floor(log10(x))+(long long)floor(log10(x)); break;
         }
         x*=10;
     }
     return n;
}
int main(){
    scanf("%lld%lld", &a,&b);
    if(a==0) { da=1; a=1; }
    else da=Bismillah(a)+1;
    if(a==0) { db=1; b=1; }
    else db=Bismillah(b)+1;
    dc=db-da+(long long)floor(log10(a))+1;
    printf("%lld\n", dc);
    return 0;
}
