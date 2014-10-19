#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;

int n,r;
double alpha,area;
int main() {
    scanf("%d%d", &n, &r);
    alpha=(double)360/n;
    alpha=(double)(alpha*acos(-1))/180;
    area=(double) (sin(alpha)*r*r*n)/2;
    printf("%.2lf\n", area);
    return 0;
}
