#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int n, p[51000];
long long total = 0;
int main() {
    scanf("%d", &n);
    R(i,0,n) {
        int a, b;
        scanf("%d%d", &a, &b);
        p[b] = max(a,p[b]);
    }
    R(i,0,50111) total+=(long long) p[i];
    printf("%lld\n", total);
    return 0;
}
