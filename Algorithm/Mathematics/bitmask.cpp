#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

LLD n, awal, akhir;
LLD ba[100], bi[100];
int main() {
    scanf("%lld%lld%lld", &n, &awal, &akhir);
    long long ta = 0, ti = 0, dua = ((LLD)1<<62);
    R(i,0,63) {
        if(awal  & dua) ta += dua;
        if(akhir & dua) ti += dua;
        ba[i] = ta;
        bi[i] = ti;
        printf("%d %lld %lld\n", i, ta, ti);
        dua >>=1;
    }
    return 0;
}
