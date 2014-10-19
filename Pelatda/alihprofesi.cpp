#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

const double eps = 1e-10;

int n;
double x[10], p, num=0.0, sum = 0.0;
int main() {
    //printf("%.2lf\n", pow(0.0,0.0));
    scanf("%d", &n);
    for(int i=0; i<=n; i++) scanf("%lf", &x[i]);
    scanf("%lf", &p);
    for(int i=1; i<=n; i++) sum += x[i];
    
    if(sum - 0 <= eps) {
        if(p - x[0] <= eps) printf("semua x memenuhi\n");
        else printf("tidak ada x yang memenuhi\n");
        return 0;
    }
    double ki = 0.0, ka = 1000.0, mid = 500.0;
    
    while( ka - ki >= eps) {
        num = 0.0;
        mid = (ka+ki)/2;
        for(int i=0; i<=n; i++) num += x[i]*pow(mid,i);
        if(num - p >= eps) {
            ka = mid;
        } else {
            ki = mid;
        }
        //printf("%.2lf %.2lf\n", mid, num);
    }
    if(mid - 0 <= eps) {
        printf("tidak ada x yang memenuhi\n");
    } else printf("%.2lf\n", mid);
    
    return 0;
}
