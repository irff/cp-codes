#include <cmath>
#include <cstdio>
using namespace std;

typedef long long LLD;

LLD n,p;
int k;
int main(){
    scanf("%lld%d", &n,&k);
    p=1;
    for(int i=0; i<k; i++) p*=10;
    n=(LLD)round((double)n/p)*p;
    printf("%lld\n", n);
    scanf("\n");
    return 0;
}
