#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, a[600];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int n;
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);
        sort(a, a+n);
        int mid = n/2, dist = 0;
        R(i,0,n) dist+=abs(a[i]-a[mid]);
        printf("%d\n", dist);
    }
    return 0;
}
