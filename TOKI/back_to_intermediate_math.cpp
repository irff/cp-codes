#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, d, v, u;
int main() {
    scanf("%d", &teskes);
    R(i,0,teskes) {
        scanf("%d%d%d", &d, &v, &u);
        double x = (double)d / u;
        double y = (double)d/sqrt((double)(u*u-v*v));
        printf("Case %d: ", i+1);
        if(u==0 or v==0 or u<=v) printf("can't determine\n");
        else printf("%.3lf\n", y-x);
    }
    return 0;
}
