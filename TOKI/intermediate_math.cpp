#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

double x, y, ans;
int d, va, vi, teskes;
int main() {
    scanf("%d", &teskes);
    R(i,0,teskes) {
        scanf("%d%d%d", &d, &va, &vi);
        x = (double)d/vi;
        double geser = (double)va*x;
        printf("geser = %.3lf\n", geser);
        double s = (double)sqrt((double)(geser*geser+d*d));
        printf("s = %.3lf\n", s);
        y = (double)s/vi;
        ans = (double) fabs(x-y);
        printf("%.3lf %.3lf\n", x, y);
        printf("Case %d:%.3lf\n", i+1, ans);
    }
    return 0;
}
