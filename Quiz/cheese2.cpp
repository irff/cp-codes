#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;
typedef pair<int,int> II;
typedef pair<II, int> III;
int n, target, kepeyokan;

int w[120], v[120];
LLD maks = -2000111222;
LLD memo[2000][3];

LLD rek(int sisa, bool peyok) {
    if(memo[sisa][peyok]==-1) {
      if(sisa == 0) return memo[sisa][peyok]=0;
      LLD ans = 0;
      R(i,0,n) {
        if(peyok) {
            if(sisa >= w[i]-(w[i]/5)) ans = max(ans, rek(sisa-(w[i]-w[i]/5),1)+v[i]);
        } else {
            if(sisa >= w[i]) {
                if(w[i] >= kepeyokan) ans = max(ans, rek(sisa-w[i], 1)+v[i]);
                else ans = max(ans, rek(sisa-w[i], 0)+v[i]);
            }
        }
      }
      return memo[sisa][peyok]=ans;
    }
    return memo[sisa][peyok];
}

int main() {
    memset(memo, -1, sizeof memo);
    scanf("%d%d%d", &n, &target, &kepeyokan);
    R(i,0,n) scanf("%d%d", &v[i], &w[i]);
    maks = rek(target, false);
    printf("%lld\n", maks);
    return 0;
}
