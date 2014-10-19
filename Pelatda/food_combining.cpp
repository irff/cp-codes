#include <cstdio>
#include <algorithm>
using namespace std;

const int MOD = 2000111222;
typedef long long LLD;

int n, lontong, maks;
LLD ans = 0;
LLD memo[1002][3][1002];
LLD rek(int ke, bool now, int udah) {
    //printf("%d %d %d\n", ke, now, udah);
    //printf("%d ", now);
    if(ke==n-1) { return 1;}
  if(!memo[ke][now][udah]) {
    LLD result = 0;
    if(now) {
        if(udah < maks) result+=rek(ke+1, now, udah+1)%MOD;
        result+=rek(ke+1, !now, 1)%MOD;
    } else {
        if(udah < lontong) result+=rek(ke+1, now, udah+1)%MOD;
        result+=rek(ke+1, !now, 1)%MOD;
    }
    
    return memo[ke][now][udah]=result;
  }
  return memo[ke][now][udah];
}

int main() {
    scanf("%d%d%d", &n, &lontong, &maks);
    lontong = min(maks, lontong);
    ans+=rek(0, 0, 1);
    ans+=rek(0, 1, 1);
    printf("%lld\n", ans);
    return 0;
}
