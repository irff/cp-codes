#include <cstdio>
using namespace std;
 
long long a, b, c, n, x, y;

long long pangkat(long a,long b,long n){
     if(b == 0) return 1;
     long long tmp = pangkat(a,b/2,n)%n;
     if(b % 2) return (a*tmp % n)*tmp % n;
     return tmp*tmp % n;
}
int main(){
    scanf("%lld%lld%lld%lld", &a,&b,&c,&n);
    
    x=a;
    for(long long i=0; i<c; i++) { x=pangkat(x,b,n); }
    
    printf("%lld\n", x+1);
    return 0;
}