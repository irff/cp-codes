#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

LLD n;
int memo[10000];
int rek(LLD n) {
    if(n<3) return n;
    if(n<9700) {
        return memo[n];
    }
    return (rek(n/2)+rek(n/2+1))%12345;
}

int main() {
    memo[1] = 1;
    memo[2] = 2;
    R(i,3,9700) {
        memo[i] = (memo[i/2]+memo[i/2+1])%12345;
    }
    scanf("%lld", &n);
    printf("%d\n", rek(n));
    return 0;
}
