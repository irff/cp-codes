#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[21000];
int main() {
    scanf("%d", &teskes);
    R(k,0,teskes) {
        scanf("%d", &n);
        R(i,0,n) scanf("%d", &a[i]);
        R(i,1,n) {
            if(a[i-1] > 0) {
                if(a[i]+a[i-1] > 0) {
                    a[i] += a[i-1];
                }
            }
        }
    }

    return 0;
}
