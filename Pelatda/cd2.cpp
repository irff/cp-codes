#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

long long maks,n,a[30],bitans,ans,sumans;
int main() {
    while(scanf("%lld", &maks)>0) {
        bitans = 0,ans=0,sumans=0;
        scanf("%lld", &n);
        R(i,0,n) scanf("%lld", &a[i]);

        for(int i=0; i<(1<<n); i++) {
            int x = i, ctr=0, sum=0, isi=0;
            for(int j=0; (1<<j)<=i; j++) {
                if(1<<j & i) sum+=a[j];
            }
            
            if(sum <= maks) {
                if(sum >= sumans) {
                    sumans = sum,bitans=i;
                }
            }
        }
        int ctr = 0;
        while(bitans>0) {
            if(bitans%2) printf("%lld ", a[ctr]);
            bitans/=2;
            ctr++;
        }
        printf("sum:%lld\n", sumans);
    }
    return 0;
}
