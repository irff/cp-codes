#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[100];
int main() {
    scanf("%d", &teskes);
    R(i,0,teskes) {
        scanf("%d", &n);
        R(j,0,n) scanf("%d", &a[j]);
        printf("Case %d: %d\n", i+1, a[n/2]);
    }
    return 0;
}
