#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[30], power[30];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        R(i,0,n) power[i] = 0;
        int sum = 0, major = 0;
        R(i,0,n) {
            scanf("%d", &a[i]);
            sum+=a[i];
        }
        major = sum/2;
        
        R(i,0,(1<<n)) {
            int now = 0;
            R(j,0,n) {
                if(i&(1<<j)) now+=a[j];
            }
            if(now > major) {
                R(j,0,n) {
                    if(i&(1<<j)) {
                        if(now-a[j] <= major) power[j]++;
                    }
                }
            }
        }
        R(i,0,n) {
            printf("party %d has power index %d\n", i+1, power[i]);
        }
        printf("\n");
    }

    return 0;
}
