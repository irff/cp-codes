#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[100], kasus = 1;
int main() {
    while(scanf("%d", &n) > 0) {
        long long sum = 0;
        R(i,0,n) {
            scanf("%d", &a[i]);
        }
        R(i,0,n) {
            R(j,i,n) {
                long long x = 1;
                R(k,i,j+1) {
                    x*=a[k];
                }
                sum = max(sum, x);
            }
        }
        printf("Case #%d: The maximum product is ", kasus);
        printf("%lld.\n", sum);
        printf("\n");
        kasus++;
    }
    return 0;
}
