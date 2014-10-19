#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int a,b; scanf("%d%d", &a, &b);
    a = max(a,b);
    a = 6-a+1;
    printf("%d/%d\n", a/__gcd(a,6), 6/__gcd(a,6));
    return 0;
}
