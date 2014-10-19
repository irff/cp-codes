#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define pi acos(-1)

long long a[3],juma,b[3],jumb;
double x,y;
int main(){
    R(i,0,3) scanf("%lld%lld", &a[i],&b[i]),juma+=a[i],jumb+=b[i];
    x=(double)juma/3;
    y=(double)jumb/3;
    printf("%.5lf %.5lf\n", x,y);
    scanf("\n");
    return 0;
}
