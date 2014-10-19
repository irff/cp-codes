#include <cstdlib>
#include <cstdio>

long long a,b;
int main() {
    scanf("%lld-%lld", &a,&b);
    printf("%lld\n", (long long) abs(a-b));
}
