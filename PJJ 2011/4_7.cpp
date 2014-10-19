#include <cstdio>
using namespace std;

long long teskes,n,n4,n7,n28;
long long total;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d", &n);
        n4 = n/4;
        n7 = n/7;
        n28 = n/28;
        total = 4*(n4*(n4+1)/2)+7*(n7*(n7+1)/2)-28*(n28*(n28+1)/2);
        printf("%lld\n", (long long)total);
        
    }

    return 0;
}
