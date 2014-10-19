#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

const LLD MOD = 1000000007;

int n;
LLD a[1010][5], ki[1000],ka[1000];
LLD ans = 0;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        scanf("%lld%lld%lld%lld", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    R(i,0,n) {
        R(j,0,n) {
            (++ki[a[i][0]+a[j][1]+400])%MOD;
            (++ka[a[i][2]+a[j][3]+400])%MOD;
        }
    }
    for(int i=-200; i<=200; i++) {
        ans =  (LLD)(ans +((LLD)ki[i+400]*(LLD)ka[400-i])%MOD)%MOD;
    }
    printf("%lld\n", ans);
    return 0;
}
