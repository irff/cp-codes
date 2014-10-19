#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes, n, a[2012], lis[2012], lds[2012];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        
        scanf("%d", &n);
        R(i,1,n+1) scanf("%d", &a[n-i]);
        R(i,0,n) {
            lis[i] = 1; lds[i] = 1;
            R(j,0,i) {
                if(a[i] > a[j] and lis[i] < lis[j]+1) {
                    lis[i] = lis[j]+1;
                }
                if(a[i] < a[j] and lds[i] < lds[j]+1) {
                    lds[i] = lds[j]+1;
                }
            }
        }
        /*
        R(i,0,n) printf("%d ", lis[i]);
        printf("\n");
        R(i,0,n) printf("%d ", lds[i]);
        printf("\n");
        */
        int ans = 0;
        R(i,0,n) {
            ans = max(ans, lis[i]+lds[i]-1);
        }
        printf("%d\n", ans);
    }

    return 0;
}
