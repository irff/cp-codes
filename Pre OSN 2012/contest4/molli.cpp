#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLD;

LLD n;

int cari(LLD x) {
     if(x==0) return 0;
     if(x==1) return 1;
     if(x%2==0) {
         return cari(x/2)+1;
     }
     return min( cari( (x-1)/2), cari( (x+1)/2))+2;
}

int main() {
    while(scanf("%lld", &n)>0) {
    printf("%d\n", cari(n));
    }
    return 0;
}
