#include <cstdio>
#include <functional>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

typedef long long LLD;

int teskes, p[3];
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        scanf("%d%d%d", &p[0], &p[1], &p[2]);
        LLD x = 0;
        sort(p, p+3, greater<int>());
        int a = p[0], b = p[1], c = p[2];
        //printf("%d %d %d\n", a, b, c);
        if(a == b and a == c) {
            x = (LLD)(a*(LLD)(b*c));
        } else if(a > b and b > c) {
            x = (LLD)(6*(LLD)(a*(LLD)(b*c))) - (LLD)(3*(LLD)(a*c)) - (LLD)(3*(LLD)(b*c)) - (LLD)(3*(LLD)(b*c)) + c;
        } else if(b==c and a>b) {
            x = (LLD)(6*(LLD)(a*(LLD)(b*c))) - (LLD)(3*(LLD)(a*b)) - (LLD)(6*(LLD)(b*b)) + b;
        } else if(a==b and b>c) {
            x = (LLD)(6*(LLD)(a*(LLD)(b*c))) - (LLD)(9*(LLD)(a*c)) + c;
        }
        printf("%lld\n", x);
    }
    return 0;
}
