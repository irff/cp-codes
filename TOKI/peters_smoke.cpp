#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

long long n, k;
int main() {
    while( scanf("%lld%lld", &n, &k) > 0) {
        long long sum = n;
        while(n>=k) {
            sum+=(long long)(n/k);
            n = (long long)(n/k)+(n%k);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
