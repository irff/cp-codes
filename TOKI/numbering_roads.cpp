#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int a, b, kasus = 0;
int main() {
    while(scanf("%d%d", &a, &b), a and b) {
        kasus++;
        int ans = (a-1)/b;
        printf("Case %d: ", kasus);
        if(ans <= 26) printf("%d\n", ans);
        else printf("impossible\n");
    }
    return 0;
}
