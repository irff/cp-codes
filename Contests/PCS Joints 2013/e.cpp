#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)
#define RV(i,_a,_b) for(int i=int(_a);i>=int(_b);i--)

typedef long long LLD;

LLD maks = 0, a[50], ans = 0;
int n;
int main() {
    scanf("%lldd%d", &maks, &n);
    R(i,0,n) {
        scanf("%lldd", &a[i]);
    }
    for(int i=0; i<(1<<n); i++) {
        LLD now = 0;
        R(j,0,n) {
            if( (i&(1<<j)) > 0) {
                if((LLD)now + (LLD)a[j] <= maks) {
                    now = (LLD)((LLD)now + (LLD)a[j]);
                    ans = (LLD)max((LLD)now, (LLD)ans);
                }
            }
        }
    }
    printf("%lldd\n", ans);
    return 0;
}
