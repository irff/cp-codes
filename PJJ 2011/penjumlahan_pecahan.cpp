#include <algorithm>
#include <cstdio>
using namespace std;

long long a,b,c,d,e,f;
int main() {
    scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
    f = b*(d/__gcd(b,d));
    e = (f/b)*a+(f/d)*c;
    printf("%lld %lld\n", e/__gcd(e,f),f/__gcd(e,f));
    return 0;
}
