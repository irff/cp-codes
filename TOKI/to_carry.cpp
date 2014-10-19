#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
LLD a, b;
int main() {
    while( scanf("%lld%lld", &a, &b) > 0){
        LLD x = 0;
        R(i,0,32) {
            bool ba = a&(1<<i);
            bool bi = b&(1<<i);
            x+=(ba^bi)*(1<<i);
        }
        printf("%lld\n", x);
    }
    return 0;
}
