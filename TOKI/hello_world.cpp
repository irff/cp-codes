#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a[10111], kasus = 0;
int main() {
    int ctr = 0;
    R(i,2,10100) {
        //printf("%d - %d\n", i, !(i&(i-1)));
        if(!((i-1)&(i-2))) {
            ctr++;
        }
        a[i] = ctr;
    }
    int n;
    while(scanf("%d", &n) and n>=0) {
        kasus++;
        printf("Case %d: %d\n", kasus, a[n]);
    }
    return 0;
}
