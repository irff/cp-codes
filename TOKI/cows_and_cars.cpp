#include <cstdio>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int k, m, open;
int main() {
    while(scanf("%d%d%d", &k, &m, &open) > 0) {
        double x = k * (double)m/(k-open-1+m);
        double y = m * (double)(m-1)/(k-open+m-1);
        double ans = (double)(x+y)/(k+m);
        
        printf("%.5lf\n", ans);
    }
    return 0;
}
