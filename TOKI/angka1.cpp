#include <cstdio>
#include <cmath>
#define MAKS 50002
using namespace std;

unsigned long long a[MAKS];
long i=1;
long fib;
int main(){
    a[i]=1;
    for(i=2; i<50002; i++) a[i]=a[i-1]+i;
    
    scanf("%d", &fib);
    for(i=1; i<=fib; i++){
        printf("%llu\n", a[i]);
    }
    
    
    return 0;
}
