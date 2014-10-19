#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int front, rear, f[100], r[100];
double d[1000];
int main() {
    while(scanf("%d", &front), front) {
        scanf("%d", &rear);
        R(i,0,front) scanf("%d", &f[i]);
        R(i,0,rear) scanf("%d", &r[i]);
        int ctr = 0;
        R(i,0,front) {
            R(j,0,rear) {
                d[ctr++] = (double)r[j] / f[i];
            }
        }
        sort(d, d+ctr);
        double ans = 0.00;
        R(i,0,ctr-1) {
            double x = (double)d[i+1]/d[i];
            if(x-ans > 1e-6) ans = x;
        }
        printf("%.2lf\n", ans);
    }

    return 0;
}
