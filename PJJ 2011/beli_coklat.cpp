#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

typedef pair<LLD,LLD> PLL;

PLL coklat[100200];
LLD n, duit, senang = 0;
/*
bool cp(PLL a, PLL b) {
    double xa = (double)a.first/a.second;
    double xb = (double)b.first/b.second;
    return xa < xb;
}
*/
int main() {
    scanf("%lld%lld", &n, &duit);
    R(i,0,n) scanf("%lld%lld", &coklat[i].first, &coklat[i].second);
    sort(coklat,coklat+n);
    //printf("---\n");
    R(i,0,n) {
        if(duit >= coklat[i].first) {
            LLD x = (LLD)duit/coklat[i].first;
            if(x >= coklat[i].second) {
                //printf("%lld ", coklat[i].first);
                //printf("%lld\n", coklat[i].second);
                senang += coklat[i].second;
                duit-=(coklat[i].second*coklat[i].first);
            } else if(x >= 1) {
                //printf("%lld ", coklat[i].first);
                //printf("%lld\n", x);
                senang += x;
                duit-=(x*coklat[i].first);
            }
        }
    }
    //printf("%lld\n", duit);
    printf("%d\n", senang);
    return 0;
}
