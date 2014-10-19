#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

const int MOD = 1000000;

int n, k, ans;
int memo[102][102];

int rek(int n, int ke) {
    //      printf("%d %d\n", n, ke);
    if(memo[n][ke]==-1) {
        if(n<0) return memo[n][ke]=0;
        if(ke==0) {
            if(n==0) return memo[n][ke]=1;
            return memo[n][ke]=0;
        }
        int ans = 0;
        R(i,0,n+1) {
            ans+=rek(n-i,ke-1);
        }
        return memo[n][ke] = ans%MOD;
    }
    return memo[n][ke];
}

int main() {
    memset(memo, -1, sizeof memo); 
    scanf("%d%d", &n, &k);
    while(n!=0 and k!=0) {
        ans = rek(n, k);
        printf("%d\n", ans);
        scanf("%d%d", &n, &k);
    }

    return 0;
}
