#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

long long n;
int main() {
    while(scanf("%lld", &n), n) {
        long long x = (long long)sqrt((double)n);
        if(x*x==n) printf("yes\n");
        else printf("no\n");
    }

    return 0;
}
