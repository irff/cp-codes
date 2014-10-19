#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LLD;

int n, aman;
LLD memo[70][3][70], ans = 0;

LLD rek(int ke, bool now, int am) {
    if(ke==n) { return (am==aman); }
    if(!memo[ke][now][am]) {
        LLD result = 0;
        if(now) {
            if(am<aman) result += rek(ke+1, 1, am+1);
            if(n-ke>=aman-am) result += rek(ke+1, 0, am);
        } else {
            if(n-ke>=aman-am) result += rek(ke+1, 0, am);
            if(n-ke>=aman-am) result += rek(ke+1, 1, am);
        }
        return memo[ke][now][am]=result;
    }
    return memo[ke][now][am];
}

int main() {
    scanf("%d%d", &n, &aman);
    while(n!=-1 and aman!=-1) {
        memset(memo, 0, sizeof memo);
        ans=rek(0, 1, 0);
        printf("%lld\n", ans);
    }
    return 0;
}
