#include <algorithm>
#include <cstdio>
using namespace std;
int teskes, a, b;

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", __gcd(a,b));
    }
    return 0;
}
