#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, radar, rumah, a[100111];

bool bisa(int rad) {
    int pos = 100111222, pasang = 0;;
    for(int i=0; i<rumah; i++) {
        if(abs(pos-a[i]) > rad) {
            pasang++;
            pos = a[i]+rad;
        }
    }
    if(pasang <= radar) return 1;
    return 0;
}

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &radar, &rumah);
        R(i,0,rumah) {
            scanf("%d", &a[i]);
            a[i]*=10;
        }
        sort(a, a+rumah);
        int low = 0, high = 10000000, mid = 0;
        for(int i=0; i<25; i++) {
            mid = (low+high)/2;
            if(bisa(mid)) {
                high = mid;
            } else {
                low = mid;
            }
        }
        printf("%.1lf\n", (double)high/10);
    }
    return 0;
}
