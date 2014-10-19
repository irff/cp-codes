#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, sum, a[10111];
int ansa = 0, ansi = 2000111222;
int main() {
    while(scanf("%d", &n) > 0) {
        ansa = 0, ansi = 2000111222;
        R(i,0,n) scanf("%d", &a[i]);
        scanf("%d", &sum);
        sort(a, a+n);
        R(i,0,n) {
            int x = sum-a[i];
            if(x>=0) {
                int ki = 0, ka = n;
                int mid = (ki+ka)/2;
                bool nemu = 0;
                for(int j = 0; j<=15 and ki<=ka; j++) {
                    mid = (ki+ka)/2;
                    if(a[mid] == x and mid!=i) nemu = 1;
                    else if(a[mid] < x) {
                        ki = mid+1;
                    } else {
                        ka = mid - 1;
                    }
                }
                if(nemu) {
                    if(max(a[i], x)-min(a[i],x) < ansi-ansa) {
                        ansi = max(a[i], x);
                        ansa = min(a[i], x);
                    }
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n", ansa, ansi);
    }
    return 0;
}
