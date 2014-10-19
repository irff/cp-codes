#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;
int teskes;
int n, k, m;
LLD memo[52][52][52];

LLD rek(int ke, int now, int in) {
    if(ke >= n) {
        if(now == k) return 1;
        return 0;
    }
    if(memo[ke][now][in] == 0) {
        LLD hasil = 0;
        if(in < m and n-ke >= k-now) {
            hasil+=rek(ke+1,now,in+1);
        }
        if(now < k) hasil+=rek(ke+1,now+1,1);
        return memo[ke][now][in] = hasil;
    }
    return memo[ke][now][in];
}

int main() {
    while( scanf("%d%d%d", &n, &k, &m) > 0) {
        LLD ans = rek(1,1,1);
        memset(memo, 0, sizeof memo);
        printf("%lld\n", ans);
    }
    return 0;
}
