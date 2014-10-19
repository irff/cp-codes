#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, a[100], kasus = 1;
int main() {
    while(scanf("%d", &n) > 0) {
        int neg = 0;
        R(i,0,n) {
            scanf("%d", &a[i]);
            if(a[i] < 0) neg++;
        }
        if(neg%2) neg--;
        sort(a,a+n);
        R(i,0,neg) a[i]*=-1;
        long long sum = 1;
        bool sukses = 0;
        R(i,0,n) {
            if(a[i]>0) {
                sukses = 1;
                sum*=(long long)a[i];
            }
        }
        printf("Case #%d: The maximum product is ", kasus);
        if(sukses) printf("%lld.\n", sum);
        else printf("0.\n");
        printf("\n");
        kasus++;
    }
    return 0;
}
