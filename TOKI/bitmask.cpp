#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD n, awal, akhir;
LLD ba[100], bi[100], ans = 0;
bool inrange(int i, LLD num) {
    if(num >= ba[i] and num <= bi[i]) return 1;
    return 0;
}
int main() {
  while( scanf("%lld%lld%lld", &n, &awal, &akhir) > 0) {
    long long ta = 0, ti = 0, dua = ((LLD)1<<62);
    
    R(i,0,63) {
        if(awal  & dua) ta += dua;
        if(akhir & dua) ti += dua;
        ba[i] = ta;
        bi[i] = ti;
        //printf("%d %lld %lld\n", i, ta, ti);
        dua >>=1;
    }
    dua = ((LLD)1<<62);
    ans = 0;

    R(i,0,63) {
        if(n & dua) {
            LLD x = ans;
            if(inrange(i,x)) {
                ans = x;
            } else {
                ans = ans | dua;
            }
        } else {
            LLD x = ans | dua;
            if(inrange(i,x)) {
                ans = x;
            } else {
                //nothing
            }
        }
        dua >>=1;
    }

    printf("%lld\n", ans);
  }
  return 0;
}
