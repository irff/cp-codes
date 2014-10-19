#include <algorithm>
#include <cstdio>
using namespace std;

long long teskes, n;
int main() {
    scanf("%lld", &teskes);
    while(teskes--) {
        scanf("%lld", &n);
        printf("%lld\n", (n*n)*(n*n+1)/(2*n));
    }
    return 0;
}
