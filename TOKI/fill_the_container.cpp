#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)


int n, m;
int a[1200];

bool check(int x) {
    if(x<*max_element(a,a+n)) return 0;
    int ctr = 1, now = 0;
    R(i,0,n) {
        now += a[i];
        if(now > x) {
            now = a[i];
            ctr++;
        }
    }
    return ctr <= m;
}

int main() {
    while(scanf("%d%d", &n, &m) > 0) {
        long long ki = 2000111222, ka = 0, mid = 0;
        R(i,0,n) { scanf("%d", &a[i]); ka+=a[i]; ki = min(ki, (long long)a[i]); }
        for(int i=0; i<33; i++) {
            mid = (ki+ka)/2;
            if(check(mid)) {
                ka = mid;
            } else ki=mid;
        }
        printf("%d\n", ka);
    }
    return 0;
}
