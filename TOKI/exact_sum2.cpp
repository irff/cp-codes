#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, sum, a[10111];
int ansa, ansi;
int main() {
    while(scanf("%d", &n) > 0) {
        R(i,0,n) scanf("%d", &a[i]);
        scanf("%d", &sum);
        sort(a, a+n);
        int ki = 0, ka = n-1, diff = 2000111222;
        while(ki<ka) {
            if(a[ki]+a[ka]==sum) {
                if(a[ka]-a[ki] < diff) {
                    diff = a[ka]-a[ki];
                    ansa = a[ki];
                    ansi = a[ka];
                    ki++, ka--;
                } 
            } else
                if(a[ka]+a[ki]>sum) ka--;
                else ki++;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", ansa, ansi);
    }
    return 0;
}
