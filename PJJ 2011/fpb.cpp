#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a); i<int(_b); i++)

int teskes, a, b;

int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d", &a, &b);
        printf("%d\n", __gcd(a,b));
    }
    return 0;
}
