#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes;
LLD a,b,c,p[4],ans;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%lld%lld%lld", &p[0], &p[1], &p[2]);
        sort(p, p+3);
        a = p[0], b = p[1], c = p[2];
        ans = 0;
        ans+= (LLD)(a*(LLD)(b*c));
        ans+= (LLD)(a*(LLD)((c-b)*b));
        ans+= (LLD)((b-a)*(LLD)(a*c));
        ans+= (LLD)((b-a)*(LLD)((c-a)*a));
        ans+= (LLD)((c-b)*(LLD)(a*b));
        ans+= (LLD)((c-b)*(LLD)((b-a)*a));
        printf("%lld\n", ans);
    }

    return 0;
}
