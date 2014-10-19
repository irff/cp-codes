#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[2000100],n;
int main() {
    scanf("%d", &n);
    R(i,0,n) scanf("%d", &a[i]);
    sort(a, a+n);
    if(n%2==0) {
        printf("%.2f\n", (double)(a[n/2-1]+a[n/2])/2);
    } else {
        printf("%.2f\n", (double)a[n/2]);
    }

    return 0;
}
