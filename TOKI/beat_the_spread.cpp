#include <cstdio>
#include <algorithm>
using namespace std;
#define R(i,_a,_b) for(int i=int(_a);i<int(_b);i++)

int teskes;
int main() {
    scanf("%d", &teskes);
    while(teskes--) {
        int a, b, c, d;
        scanf("%d%d", &c, &d);
        a = (c+d)/2;
        b = c-a;
        if(b >= 0 and a+b==c and a-b==d) {
            printf("%d %d\n", a, b);
        } else printf("impossible\n");
    }

    return 0;
}
