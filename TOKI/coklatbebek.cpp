#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

long long n,x,tmp;
int main(){
    scanf("%lld", &n);
    tmp=(long long) sqrt(n*2);
    for(long long i=tmp-1; i<tmp+2; i++){
        if( i*( i+1 ) / 2  > n) { printf("%lld\n", i); break; }
    }
    return 0;
}
