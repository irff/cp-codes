#include <cstdio>
#include <algorithm>
using namespace std;

long long n, m, a;
int main() {
    scanf("%d%d%d", &n, &m, &a);
    long long ver=0, hor=0;
    if( n%a==0 ) hor=n/a;
    else hor=n/a+1;
    if( m%a==0 ) ver=m/a;
    else ver=m/a+1;
    printf("%I64d\n", hor*ver);
    
    return 0;
}
