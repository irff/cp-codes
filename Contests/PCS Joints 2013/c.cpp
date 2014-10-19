#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

int pricea, priceb;
int ax, ay;
int bx, by;
int x, y;
int maksa, maksb;
LLD ans = 0;
int main() {
    scanf("%d%d", &pricea, &priceb);
    scanf("%d%d", &ax, &ay);
    scanf("%d%d", &bx, &by);
    scanf("%d%d", &x, &y);
    R(i,0,1000+1) {
        R(j,0,1000+1) {
            int pax = ax*i, pay = ay*i;
            int pbx = bx*j, pby = by*j;
            if(pax+pbx <= x and pay+pby <= y) {
                ans = max(ans, (LLD)i*pricea + (LLD)j*priceb);
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
